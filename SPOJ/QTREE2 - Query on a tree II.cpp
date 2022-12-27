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

int n,curtime;
LL arr[N], tree[4*N], lazy[4*N];
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

void build(LL node, LL b, LL e)
{
    if(b == e)
    {
        tree[node] = arr[flatTree[e]];
        return;
    }
    LL mid = (b + e)>>1LL;
    LL left = node<<1LL;
    LL right = left + 1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node] = tree[left] + tree[right];
}

void prop(LL node, LL b, LL e)
{
    if(b!=e)
    {
        LL mid=(b+e)>>1LL;
        LL left=node<<1LL;
        LL right=left+1;
        lazy[left]+=lazy[node];
        lazy[right]+=lazy[node];
        tree[left]+=(mid-b+1)*lazy[node];
        tree[right]+=(e-mid)*lazy[node];
    }
    lazy[node]=0;
}

LL query(LL node, LL b, LL e, LL i, LL j)
{
    if(lazy[node]!=0) prop(node,b,e);
    if(b > j or e < i) return 0;
    if(b >= i and e <= j) return tree[node];
    LL mid = (b+e)>>1LL;
    LL left = node<<1LL;
    LL right = left + 1;
    LL p = query(left,b,mid,i,j);
    LL q = query(right,mid+1,e,i,j);
    return (LL)(p+q);
}

void cleanHLD(int n)
{
    for(int i=0; i<=n; i++) if(adj[i].size()) adj[i].clear();
    parent.clear(); mxChild.clear(); level.clear(); head.clear(); pos.clear(); subsz.clear();
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
LL get_lca(int u,int v)
{
    int h1 = head[u], h2 = head[v];
    if( h1==h2 )return (level[u]<level[v]) ? u:v;
    if( level[h1]<level[h2] ) return get_lca(u,parent[h2]);
    else return get_lca(parent[h1],v);
}


int go_up_query(int u,int v)
{
    int res = 0;
    int hu = head[u], hv = head[v];
    while(1)
    {
        if( head[u]==hv )
        {
            res+=query(1,1,curtime,pos[v]+1,pos[u]);
            break;
        }
        res+=query(1,1,curtime,pos[ head[u] ],pos[u]);
        u = parent[ head[u] ];
    }
    return res;
}

LL range_query(int u,int v)
{
    if( u==v ) return go_up_query(u,v);
    int l = get_lca(u,v);
    if( l==u ) return go_up_query(v,l);
    if( l==v ) return go_up_query(u,l);
    LL x = go_up_query(u,l)+go_up_query(v,l)-go_up_query(l,l);
    return x;
}

int cnt_path_node(int u,int v)
{
    int cnt=0;
    int hu = head[u], hv = head[v];
    while(1)
    {
        if( head[u]==hv )
        {
            int curtot=pos[u]-pos[v]+1;
            cnt+=curtot;
            break;
        }
        int pos_u_head=pos[ head[u] ];
        int pos_u=pos[u];
        int curtot=pos_u-pos_u_head+1;
        cnt+=curtot;
        u = parent[ head[u] ];
    }
    return cnt;
}

int find_kth_node(int u,int v,int k)
{
    int res = 0, cnt=0;
    int hu = head[u], hv = head[v];
    while(1)
    {
        if( head[u]==hv )
        {
            int pos_u=pos[u];
            int need=k-cnt;
            int pos=pos_u-need+1;
            res=flatTree[pos];
            break;
        }
        int pos_u_head=pos[ head[u] ];
        int pos_u=pos[u];
        int curtot=pos_u-pos_u_head+1;
        if(cnt+curtot<k)
        {
            cnt+=curtot;
        }
        else
        {
            int need=k-cnt;
            int pos=pos_u-need+1;
            res=flatTree[pos];
            break;
        }
        u = parent[ head[u] ];
    }
    return res;
}

LL path_kth_node(int u,int v,int k)
{
    if( u==v ) return u;
    int l = get_lca(u,v);
    int u_to_l=cnt_path_node(u,l);
    if(u_to_l>=k) return find_kth_node(u,l,k);
    else
    {
        int v_to_l=cnt_path_node(v,l);
        int need= k-u_to_l;
        need=v_to_l-need;
        return find_kth_node(v,l,need);
    }
}

vector<PII>adj2[N];
void mydfs(int u, int par)
{
    for(PII v:adj2[u])
    {
        if(v.first!=par)
        {
            mydfs(v.first,u);
            arr[v.first]=v.second;
        }
    }
}

void solve(int casenum)
{
    cin>>n;
    cleanHLD(n);
    cleanSegTree(n);
    For(i,1,n)if(sz(adj2[i]))adj2[i].clear();

    int u,v,w;
    For(i,1,n-1)
    {
        cin>>u>>v>>w;
        addEdge(u,v);
        adj2[u].PB({v,w});
        adj2[v].PB({u,w});
    }
    mydfs(1,0);
    init();

    while (1)
    {
        string str;
        cin>>str;
        if(str=="DONE") break;
        else if(str=="DIST")
        {
            int u,v;
            cin>>u>>v;
            if(u==v) cout<<0<<NL;
            else
            {
                int ans=range_query(u,v);
                cout<<ans<<NL;
            }
        }
        else
        {
            int u,v,k;
            cin>>u>>v>>k;
            int ans=path_kth_node(u,v,k);
            cout<<ans<<NL;
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

    flatTree.resize(N+1);

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link: https://www.spoj.com/problems/QTREE2/

Sol : Give the edge value to the child of corresponding parent.
Suppose, 1 -> 2 = 4, 2 -> 3 = 5
Then node 2 will contain value 4 and node 3 will contain value 5 
mydfs() handles this

In answering dist query, we are ignoring LCA value.
In go_up_query(), when node u is in the chain of LCA node, we made the query
from the next of LCA to u.

In answering kth query, we first checked if u to lca(u,v) have k nodes, if yes then we just
go upto the kth node, else we have to traverse the path of v to lca(u,v) for the remaining nodes
to find the kth node.

*/