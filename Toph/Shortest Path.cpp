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

const int N = 5e5 + 10;
const int MOD = 1000000007;

int n,m,q;
vector<int>adj[N],path_nodes;
int level[N];
bool visited[N];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for(int v:adj[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
}

void get_nodes(int s,int t)
{
    int s_level=level[s];
    int t_level=level[t];
    path_nodes.PB(t);
    queue<PII>q;
    q.push({t,t_level});
    while (!q.empty() and t_level>=s_level)
    {
        int cur_node=q.front().first; 
        int cur_level=q.front().second;
        int need_level=cur_level-1;
        q.pop();
        for(int v:adj[cur_node])
        {
            if(level[v]==need_level)
            {
                q.push({v,need_level});
                path_nodes.PB(v);
            }
        }
    }
}

void multisource_bfs()
{
    mem(visited,false);
    mem(level,0);
    queue<int>q;
    for(int v:path_nodes)
    {
        q.push(v);
        visited[v]=true;
    }
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for(int v:adj[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
}

void solve(int casenum)
{
    cin>>n>>m>>q;
    int u,v;
    For(i,1,m)
    {
        cin>>u>>v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    int s,t;
    cin>>s>>t;
    bfs(s);
    get_nodes(s,t);
    multisource_bfs();
    while (q--)
    {
        int node;
        cin>>node;
        int ans=level[node];
        cout<<ans<<NL;
    }
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://toph.co/p/shortest-path

*/
