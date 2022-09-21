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

const int N = 2e6 + 10;
const int MOD = 1000000007;

LL n, r;
LL fact[N+5], invFact[N+5];

inline LL power_mod(LL base, LL power, LL mod){
   LL p1 = 0, p2 = 0;
   if(power==0) return 1LL;
   else if(power%2LL == 1){
       p1 = base % mod; p2 = (power_mod(base,power-1,mod))%mod;
       p1 = (LL)(p1*p2)%mod;
   }
   else if(power%2LL == 0){
       p1 = (power_mod(base,power/2LL,mod))%mod; p1 = (LL)(p1*p1);
   }
   return p1%mod;
}

LL modInverse(LL base, LL mod)
{
    return power_mod(base,mod-2,mod);
}

void precal()
{
    fact[0] = 1;
    for(int i=1; i<=N; i++)
    {
        fact[i] = ((fact[i-1]%MOD) * (i%MOD)) %MOD;
    }
    invFact[0] = 1;
    invFact[N] = modInverse(fact[N],MOD);
    for(int i=N-1; i>=1; i--)
    {
        invFact[i] = ((invFact[i+1]%MOD) * ((i+1)%MOD)) % MOD;
    }
}

LL nCr(LL n, LL r)
{
    if(r > n) return 0;
    LL x = fact[n];
    LL y = invFact[r];
    LL z = invFact[n-r];
    LL ncr = (((x * y) % MOD) * z) % MOD;
    return (LL)(ncr % MOD);
}

void solve(int casenum)
{
    cin>>n>>r;
    LL up = (n + (r - 1));
    LL down = r - 1;
    LL ans = nCr(up,down);
    cout<<"Case "<<casenum<<": "<<ans<<endl;
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    precal();

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/problem-makes-problem

Sol : Based on stars and bars theorem.
Putting (r-1) bars into (n+(r-1)) boxes. In how many ways we can arrange them
is the answer.
Answer : (n+(r-1))c(r-1)

*/

