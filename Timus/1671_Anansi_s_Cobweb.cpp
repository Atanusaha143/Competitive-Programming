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

int n,m,q,components;

struct info
{
    int u,v;
};
info arr[N];
int parent[N], queries[N];

int Find(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=Find(parent[a]);
}
void Union(int a, int b)
{
    a=Find(a);
    b=Find(b);
    if(a!=b)
    {
        parent[a]=b;
        components--;
    }
}

void solve(int casenum)
{
    cin>>n>>m;
    int u,v;
    For(i,1,m)
    {
        cin>>u>>v;
        arr[i].u=u;
        arr[i].v=v;
    }

    set<int>st;
    For(i,1,n)
    {
        parent[i]=i;
    }
    For(i,1,m)
    {
        st.insert(i);
    }
    
    cin>>q;
    For(i,1,q)
    {
        int edgenum;
        cin>>edgenum;
        queries[i]=edgenum;
        st.erase(edgenum);
    }

    // remaing graph is the current answer if we want to traverse DSU from reverse
    components=n;
    for(int edgenum:st)
    {
        int u=arr[edgenum].u;
        int v=arr[edgenum].v;
        Union(u,v);
    }

    For(i,1,n) Find(i);

    // traverse query from back thinking that we are adding the edge in our graph
    vector<int>ans;
    ans.PB(components);
    Rof(i,q,2)
    {
        int u=arr[queries[i]].u;
        int v=arr[queries[i]].v;
        Union(u,v);
        ans.PB(components);
    }

    reverse(all(ans));
    For(i,0,sz(ans)-1)
    {
        cout<<ans[i];
        if(i!=sz(ans)-1) cout<<" ";
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

Link : https://acm.timus.ru/problem.aspx?space=1&num=1671

*/