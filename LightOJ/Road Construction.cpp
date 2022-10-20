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

const int N = 50 + 10;
const int MOD = 1000000007;

vector <int> adj[N];
bool used[N];

void dfs(int s)
{
    if(used[s]) return;
    used[s] = true;
    for(auto v : adj[s])
    {
        if(!used[v])
        {
            dfs(v);
        }
    }
}

struct edge{
    int u, v, w;
};

int n, parent[N], ans;
edge arr[N];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int Find(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b, int idx)
{
    a = Find(a);
    b = Find(b);
    if(a != b)
    {
        parent[b] = a;
        ans += arr[idx].w;
    }
}

void clean()
{
    for(int i=0; i<=N; i++)
    {
        adj[i].clear();
    }
    ans = 0;
}

void solve(int casenum)
{

    clean();

    int m;
    cin>>m;

    string u, v;
    int cost;
    map <string,int> compress;
    map <PII,int> visited; 
    int id = 0;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>cost;
        if(compress.find(u) == compress.end()) compress[u] = ++id;
        if(compress.find(v) == compress.end()) compress[v] = ++id;

        int cur_u = compress[u];
        int cur_v = compress[v];
        if(cur_u > cur_v) swap(cur_u,cur_v);

        if(visited.find({ cur_u,cur_v }) != visited.end())
        {
            int w = visited[{cur_u,cur_v}];
            if(cost < w)
            {
                visited[{cur_u,cur_v}] = cost;
            }
        }
        else visited[{cur_u,cur_v}] = cost;
    }

    int eid = 0;
    for(auto x : visited)
    {
        int u = x.first.first;
        int v = x.first.second;
        int w = x.second;
        ++eid;
        arr[eid].u = u;
        arr[eid].v = v;
        arr[eid].w = w;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    mem(used,false);
    dfs(1);
    cout<<"Case "<<casenum<<": ";
    for(int i=1; i<=id; i++)
    {
        if(used[i]==false)
        {
            cout<<"Impossible"<<endl;
            return;
        }
    }
    
    sort(arr+1, arr+eid+1, cmp);
    for(int i=1; i<=id; i++) parent[i] = i;
    for(int i=1; i<=eid; i++)
    {
        int a = arr[i].u;
        int b = arr[i].v;
        Union(a,b,i);
    }
    cout<<ans<<endl;
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

Link : https://lightoj.com/problem/road-construction

*/