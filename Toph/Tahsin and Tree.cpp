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

const int N = 1e5 + 10;
const int MOD = 1000000007;

int n,q;
vector<int>adj[N];
int arr[N],freq[N];

void clean(int n)
{
    For(i,1,n)
    {
        if(sz(adj[i])) adj[i].clear();
        freq[i]=0;
    }
}

void dfs(int u, int p, int cnt)
{
    if(cnt%2)
    {
        if(arr[u]==0)arr[u]=1;
        else arr[u]=0;
    }
    for(int v:adj[u])
    {
        if(v!=p)
        {
            dfs(v,u,cnt+freq[v]);
        }
    }
}

void solve(int casenum)
{
    cin>>n>>q;
    clean(n);

    For(i,1,n)
    {
        cin>>arr[i];
    }
    int u,v;
    For(i,2,n)
    {
        cin>>u>>v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    while (q--)
    {
        int node;
        cin>>node;
        freq[node]++;
    }
    dfs(1,-1,freq[1]);

    cout<<"Case "<<casenum<<": ";
    For(i,1,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<NL;
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

Link : https://toph.co/p/tahsin-and-tree

*/