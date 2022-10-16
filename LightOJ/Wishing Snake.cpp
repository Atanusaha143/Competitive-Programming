#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define PI              (2.0*acos(0.0))
#define PB              push_back
#define MP              make_pair
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
#define now             cerr<<"Here"<<endl;
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
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

const int N = 1000 + 10;
const int MOD = 1000000007;

int clr;
vector <int> adj[N], adj_rev[N], new_adj[N], all_adj[N];
bool visited[N];
int compress[N], color[N];
vector <int> order;

void check(int s)
{
    if(visited[s]) return;
    visited[s] = true;
    for(int v : all_adj[s])
    {
        if(!visited[v])
        {
            check(v);
        }
    }
}

void dfs1(int s)
{
    if(visited[s]) return;
    visited[s] = true;
    for(int v : adj[s])
    {
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    order.PB(s);
}

void dfs2(int s)
{
    if(visited[s]) return;
    visited[s] = true;
    color[s] = clr;
    for(int v : adj_rev[s])
    {
        if(!visited[v])
        {
            dfs2(v);
        }
    }
}

void dfs3(int s)
{
    if(visited[s]) return;
    visited[s] = true;
    for(int v : new_adj[s])
    {
        if(!visited[v])
        {
            dfs3(v);
        }
    }
}

void clean()
{
    for(int i=0; i<=1000; i++)
    {
        if(adj[i].size()) adj[i].clear();
        if(adj_rev[i].size()) adj_rev[i].clear();
        if(all_adj[i].size()) all_adj[i].clear();
        if(new_adj[i].size()) new_adj[i].clear();
        visited[i] = false;
        color[i] = 0;
        compress[i] = 0;
    }
    clr = 0;
    if(order.size()) order.clear();
}

void solve(int casenum)
{

    clean();

    int n, k;
    cin>>n;

    vector <PII> edges;
    int id = 0;
    for(int i=1; i<=n; i++)
    {
        cin>>k;
        for(int j=1, u, v; j<=k; j++)
        {
            cin>>u>>v;
            if(compress[u] == 0)
            {
                compress[u] = ++id;
            }
            if(compress[v] == 0)
            {
                compress[v] = ++id;
            }
            int newu = compress[u];
            int newv = compress[v];
            edges.PB({newu,newv});
        }
    }

    for(auto x : edges)
    {
        int u = x.first;
        int v = x.second;
        adj[u].PB(v);
        adj_rev[v].PB(u);
        all_adj[u].PB(v);
        all_adj[v].PB(u);
    }

    mem(visited,false);
    check(compress[0]); ///  Initially the snake is at checkpoint 0

    cout<<"Case "<<casenum<<": ";
    for(int i=1; i<=id; i++)
    {
        if(!visited[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    mem(visited,false);
    for(int i=1; i<=id; i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }

    mem(visited,false);
    reverse(all(order));

    for(int x : order)
    {
        if(!visited[x])
        {
            clr++;
            dfs2(x);
        }
    }

    /// Building the new graph (DAG) keeping every sccs as a node.
    vector <int> vec;
    for(auto x : edges)
    {
        int u = x.first;
        int v = x.second;
        if(color[u] != color[v])
        {
            new_adj[ color[u] ].PB( color[v] );
            vec.PB( color[u] );
            vec.PB( color[v] );
        }
    }
    asort(vec); unq(vec);

    for(auto x : vec)
    {
        if(new_adj[x].size() > 1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    mem(visited,false);
    dfs3(color[ compress[0] ]);

    for(auto x : vec)
    {
        if(!visited[x])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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

Link : https://lightoj.com/problem/wishing-snake

Sol : Create DAG from SCC and just check if every node is reachable 
form the starting node (i.e node 0) by a single dfs

*/