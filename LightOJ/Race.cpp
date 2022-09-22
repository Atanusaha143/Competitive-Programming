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

const int N = 1e3 + 10;
const int MOD = 10056;

LL n;
LL dpNCR[N][N], dp[N];

LL nCr(LL n, LL r)
{
    if(n < r) return 0;
    if(r == 1) return n%MOD;
    if(dpNCR[n][r] != -1) return dpNCR[n][r];
    LL res = (nCr(n-1,r-1)%MOD + nCr(n-1,r)%MOD)%MOD;
    return dpNCR[n][r] = res%MOD;
}

LL fun(LL n)
{
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    LL val = 0;
    for(int i=1; i<=n; i++)
    {
        val = ((val % MOD) + (nCr(n,i)%MOD * fun(n-i)%MOD)%MOD )%MOD;
    }
    return dp[n] = val%MOD;
}

void solve(int casenum)
{
    cin>>n;
    LL ans = fun(n) % MOD;
    cout<<"Case "<<casenum<<": "<<ans<<endl;   
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    mem(dpNCR,-1);
    mem(dp,-1);

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/race

Sol : Let us assume that out of n horses we want k horses to be placed first.
Then the remaining (n-k) horses will be placed second or higher means out of 
(n-k) horses we want l horses to be placed second or higher. This will 
continue until we left with 0 horses.
DP[i] = number of ways a race can finish with i horses.

*/