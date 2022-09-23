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

///------------------------------------------------------------------------------------------------------------------------

const int N = 1e5 + 10;
const int MOD = 1000000007;

map <int,int> compress;
map <int,bool> visited;
vector <PII> segments;
vector <int> vec;
int n, q, ans[N];

void clean()
{
    compress.clear();
    visited.clear();
    segments.clear();
    vec.clear();
    for(int i=0; i<N; i++)
    {
        ans[i] = 0;
    }
}

void solve(int casenum)
{
    clean();

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int l, r;
        cin>>l>>r;
        segments.push_back({l,r});
        if(visited.find(l) == visited.end())
        {
            vec.push_back(l);
            visited[l] = true;
        }
        if(visited.find(r) == visited.end())
        {
            vec.push_back(r);
            visited[r] = true;
        }
    }
    sort(vec.begin(),vec.end());
    vec.push_back(1e9);
    int idx = 0;
    for(int i=0; i<vec.size(); i++)
    {
        compress[ vec[i] ] = ++idx;
    }
    for(int i=0; i<segments.size(); i++)
    {
        int l = compress[ segments[i].first ];
        int r = compress[ segments[i].second ];
        ans[l]++, ans[r+1]--;
    }

    for(int i=1; i<=idx; i++)
    {
        ans[i] = ans[i] + ans[i-1];
    }
    int res = 0;
    for(int i=0; i<=idx; i++)
    {
        res = max(res,ans[i]);
    }
    cout<<"Case "<<casenum<<": "<<res<<endl;
      
    
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

Link : https://lightoj.com/problem/monitoring-processes

*/

