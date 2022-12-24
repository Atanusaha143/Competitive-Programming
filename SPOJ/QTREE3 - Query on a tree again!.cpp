#include <bits/stdc++.h>
using namespace std;

#define NL              '\n'
#define PINF            INT_MAX
#define NINF            INT_MIN
#define sz(x)           x.size()
#define PB              push_back
#define MP              make_pair
#define asort(x)        sort(all(x));
#define PI              (2.0*acos(0.0))
#define all(x)          x.begin(),x.end()
#define Now             cerr<<"Here"<<endl;
#define For(i, j, k)    for(int i = j; i <= k; i++)
#define Rof(i, j, k)    for(int i = j; i >= k; i--)
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL  my_rand(LL l, LL r) { return uniform_int_distribution<LL>(l, r) (rng); }

#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

///---------------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------------

const int N = 1e6 + 10;
const int MOD = 1000000007;

int n,q,curtime;
int arr[N], tree[4*N], lazy[4*N];
vector<int> adj[N];
vector<int> parent,mxChild,head,pos,level,subsz,flatTree;

void cleanSegTree(int n)
{
    For(i,1,4*n)
    {
        tree[i]=0;
        lazy[i]=0;
    }
}

inline void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[flatTree[e]];
        return;
    }
    int mid = (b + e)>>1;
    int left = node<<1;
    int right = left + 1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node] = max(tree[left],tree[right]);
}

inline void prop(int node, int b, int e)
{
    if(b!=e)
    {
        int mid=(b+e)>>1;
        int left=node<<1;
        int right=left+1;
        lazy[left]=lazy[node];
        lazy[right]=lazy[node];
        tree[left]=lazy[node];
        tree[right]=lazy[node];
    }
    lazy[node]=0;
}

inline void update(int node, int b, int e, int i, int j, int val)
{
    if(lazy[node]!=0)
    {
        prop(node,b,e);
    }
    if(b > j or e < i) return;
    if(b >= i and e <= j)
    {
        tree[node]=val;
        lazy[node]=val;
        if(lazy[node]!=0) prop(node,b,e);
        return;
    }
    int mid = (b+e)>>1;
    int left = node<<1;
    int right = left + 1;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node] = max(tree[left],tree[right]);
}

inline int query(int node, int b, int e, int i, int j)
{
    if(lazy[node]!=0)
    {
        prop(node,b,e);
    }
    if(b > j or e < i) return 0;
    if(b >= i and e <= j)
    {
        return tree[node];
    }
    int mid = (b+e)>>1LL;
    int left = node<<1LL;
    int right = left + 1;
    int p = query(left,b,mid,i,j);
    int q = query(right,mid+1,e,i,j);
    return max(p,q);
}

void cleanHLD(int n)
{
    for(int i=0; i<=n; i++) if(adj[i].size()) adj[i].clear();
    parent.resize(n+1,-1);
    mxChild.resize(n+1,-1); /// stores special child of each node
    level.resize(n+1,0);
    head.resize(n+1); /// stores chain head of each node
    pos.resize(n+1); /// stores discover time of each node / position in chain
    subsz.resize(n+1,0); /// stores subtree size of each node
    curtime=0;
}

void addEdge(int u, int v)
{
	adj[u].PB(v);
	adj[v].PB(u);
}

void dfs(int u, int p)
{
    subsz[u] = 1;
    int tot = 0;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if( v!=p )
        {
            level[v] = level[u]+1;
            parent[v] = u;
            dfs(v,u);
            subsz[u] += subsz[v];
            if( subsz[v]>tot )
            {
                mxChild[u] = v;
                tot = subsz[v];
            }
        }
    }
}

/// creating chain through special child
void init_hld(int u, int p, int h)
{
    head[u]=h, pos[u]=++curtime;
    flatTree[curtime]=u;
    if( mxChild[u]!= -1 ) init_hld(mxChild[u],u,h);
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
		if( v==p || v==mxChild[u] )continue;
		init_hld(v,u,v);
    }
}

void init()
{
	level[1] = 1;
    dfs(1,0);
    init_hld(1,0,1);
    build(1,1,curtime);
}

/// traverse chain by chain
int get_lca(int u,int v)
{
    int h1 = head[u], h2 = head[v];
    if( h1==h2 )return (level[u]<level[v]) ? u:v;
    if( level[h1]<level[h2] ) return get_lca(u,parent[h2]);
    else return get_lca(parent[h1],v);
}

/// u goes to v
void go_up_update(int u,int v,int w)
{
    int hu = head[u], hv = head[v];
    while(1)
    {
        if( head[u]==hv )
        {
            update(1,1,curtime,pos[v],pos[u],w);
            break;
        }
        update(1,1,curtime,pos[ head[u] ],pos[u],w);
        u = parent[ head[u] ];
    }
}

int get_idx(int l, int r)
{
    int low=l,high=r,mid,ans=-1;
    while (low<=high)
    {
        mid=low+(high-low)/2;
        int qans=query(1,1,curtime,l,mid);
        if(qans==1)
        {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

/// u goes to v
int go_up_query(int u,int v)
{
    int res = -1;
    int hu = head[u], hv = head[v];
    while(1)
    {
        if( head[u]==hv )
        {
            res=get_idx(pos[v],pos[u]); // gives the index of the leftmost black node in this node if exists 
            break;
        }
        res=get_idx(pos[ head[u] ],pos[u]); // gives the index of the leftmost black node in this node if exists 
        u = parent[ head[u] ];
    }
    return res;
}


void range_update(int u,int v,int w)
{
    if( u==v )
    {
        go_up_update(u,v,w);
        return;
    }
    int l = get_lca(u,v);
    if( l==u )
    {
        go_up_update(v,l,w);
        return;
    }
    if( l==v )
    {
        go_up_update(u,l,w);
        return;
    }
    go_up_update(u,l,w);
    go_up_update(v,l,w);
}

int range_query(int u,int v)
{
    if( u==v )
    {
        return go_up_query(u,v);
    }
    int l = get_lca(u,v);
    if( l==u )
    {
        return go_up_query(v,l);
    }
    if( l==v )
    {
        return go_up_query(u,l);
    }
}

void solve(int casenum)
{
    cin>>n>>q;
    cleanHLD(n);
    cleanSegTree(n);

    int u,v;
    For(i,1,n-1)
    {
        cin>>u>>v;
        addEdge(u,v);
    }
    init();

    while (q--)
    {
        int typ;
        cin>>typ;
        if(typ==0)
        {
            int node;
            cin>>node;
            int curcondition=query(1,1,curtime,node,node);
            if(curcondition==1) range_update(node,node,0);
            else range_update(node,node,1);
        }
        else
        {
            int v;
            cin>>v;
            int ans=range_query(1,v);
            if(ans==-1) cout<<ans<<NL;
            else cout<<flatTree[ans]<<NL;
        }
    }
    
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    flatTree.resize(N);

    int t = 1;
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://www.spoj.com/problems/QTREE3/en/

Sol : Mark each index when you get an update query.
At the time of answer query, go to each chain and search for the leftmost black node.

*/
