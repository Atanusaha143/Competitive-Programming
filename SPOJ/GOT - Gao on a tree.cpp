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

const int N = 2e5 + 10;
const int MOD = 1000000007;

int n,q,curtime;
int arr[N];
vector<int>adj[N],tree[4*N];
vector<int>parent,mxChild,head,pos,level,subsz,flatTree;

void cleanTree(int n)
{
    For(i,0,4*n) if(sz(tree[i])) tree[i].clear();
}

void combine(vector<int>&node, vector<int>&left, vector<int>&right)
{
    int left_len=sz(left),right_len=sz(right);
    int i=0,j=0;
    while (i<left_len and j<right_len)
    {
        if(left[i]<right[j]) node.PB(left[i]), i++;
        else node.PB(right[j]), j++;
    }
    while (i<left_len)
    {
        node.PB(left[i]);
        i++;
    }
    while (j<right_len)
    {
        node.PB(right[j]);
        j++;
    }
}

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].PB(arr[flatTree[e]]);
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    build(left,b,mid);
    build(right,mid+1,e);
    combine(tree[node],tree[left],tree[right]);
}
int findResult(vector<int>&vec, int k)
{
    int l=0,r=sz(vec)-1,mid;
    while (l<=r)
    {
        mid=l+(r-l)/2;
        if(vec[mid]==k) return 1;
        else if(vec[mid]<k) l=mid+1;
        else r=mid-1;
    }
    return 0;
}
int query(int node, int b, int e, int i, int j, int k)
{
    if(b>j or e<i) return 0;
    if(b>=i and e<=j)
    {
        int qans=findResult(tree[node],k);
        return qans;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    int p=query(left,b,mid,i,j,k);
    int q=query(right,mid+1,e,i,j,k);
    return (p|q);
}
void cleanHLD(int n)
{
    For(i,0,n) if(sz(adj[i])) adj[i].clear();
    parent.clear(); mxChild.clear(); level.clear(); head.clear(); pos.clear(); subsz.clear();
    parent.resize(n+1,-1);
    mxChild.resize(n+1,-1);
    level.resize(n+1,0);
    head.resize(n+1);
    pos.resize(n+1);
    subsz.resize(n+1,0);
    curtime=0;
}
void addEdge(int u, int v)
{
	adj[u].PB(v);
	adj[v].PB(u);
}
void dfs(int u, int p)
{
    subsz[u]=1;
    int tot=0;
    for(int v:adj[u])
    {
        if(v!=p)
        {
            level[v]=level[u]+1;
            parent[v]=u;
            dfs(v,u);
            subsz[u]+=subsz[v];
            if(subsz[v]>tot)
            {
                mxChild[u]=v;
                tot=subsz[v];
            }
        }
    }
}
void init_hld(int u, int p, int h)
{
    head[u]=h, pos[u]=++curtime;
    flatTree[curtime]=u;
    if(mxChild[u]!=-1) init_hld(mxChild[u],u,h);
    for(int v:adj[u])
    {
        if(v==p or v==mxChild[u]) continue;
        init_hld(v,u,v);
    }
}
void init()
{
    level[1]=1;
    dfs(1,0);
    init_hld(1,0,1);
    build(1,1,curtime);
}
int get_lca(int u, int v)
{
    int hu=head[u], hv=head[v];
    if(hu==hv) return (level[u]<level[v])?u:v;
    if(level[hu]<level[hv]) return get_lca(u,parent[hv]);
    else return get_lca(parent[hu],v);
}
int go_up_query(int u, int v, int k)
{
    int res=0;
    int hu=head[u], hv=head[v];
    while (1)
    {
        if(head[u]==hv)
        {
            res|=query(1,1,curtime,pos[v],pos[u],k);
            break;
        }
        res|=query(1,1,curtime,pos[head[u]],pos[u],k);
        u=parent[head[u]];
    }
    return res;
}
int range_query(int u, int v, int k)
{
    if(u==v) return go_up_query(u,v,k);
    int l=get_lca(u,v);
    if(l==u) return go_up_query(v,l,k);
    if(l==v) return go_up_query(u,l,k);
    int x=go_up_query(u,l,k);
    x|=go_up_query(v,l,k);
    return x;
}
void solve(int casenum)
{
    while (cin>>n>>q)
    {
        cleanHLD(n);
        cleanTree(n);

        For(i,1,n)
        {
            cin>>arr[i];
        }
        int u,v;
        For(i,1,n-1)
        {
            cin>>u>>v;
            addEdge(u,v);
        }
        init();

        while (q--)
        {
            int u,v,k;
            cin>>u>>v>>k;
            int ans=range_query(u,v,k);
            if(ans) cout<<"Find"<<NL;
            else cout<<"NotFind"<<NL;
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
    // cin>>t;  
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://www.spoj.com/problems/GOT/

*/
