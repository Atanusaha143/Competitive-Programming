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

int n;
vector<int>adj[N],leaves;
int parent[N];
map<PII,int>mp;

void dfs(int u, int p)
{
    if(sz(adj[u])==1 and u!=1)
    {
        leaves.PB(u);
        return;
    }
    for(int v:adj[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            parent[v]=u;
        }
    }
}

void clean()
{
    For(i,1,n)
    {
        if(sz(adj[i])) adj[i].clear();
        parent[i]=-1;
    }
    mp.clear();
    leaves.clear();
}

void solve(int casenum)
{
    cin>>n;
    int u,v,w,tot=0;
    For(i,1,n-1)
    {
        cin>>u>>v>>w;
        if(u>v) swap(u,v);
        adj[u].PB(v);
        adj[v].PB(u);
        mp[{u,v}]=w;
        mp[{v,u}]=w;
        tot+=w;
    }

    dfs(1,-1);
    parent[1]=-1;
    int ans=0;
    for(int v:leaves)
    {
        int u=parent[v], cost=0;
        while (u!=-1)
        {
            cost+=mp[{u,v}];
            v=u;
            u=parent[u];
        }
        ans=max(ans,cost);
    }
    ans=((tot-ans)*2)+ans;
    cout<<"Case "<<casenum<<": "<<ans<<NL;

    clean();
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link: https://toph.co/p/road-minister-techboy

Sol: As it is a tree, we will alaways get a simple path from source node to any leaf node
whose edges will be visited once and other edges twice. So, we have to find that simple path.

Time Complexity: T*N*N where 
T = number of test cases
N = Number of nodes

*/