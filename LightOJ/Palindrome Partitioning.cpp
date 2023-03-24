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

const int MAXN=1000006;
struct DoubleHash{
    LL P[2][MAXN];
    LL H[2][MAXN];
    LL R[2][MAXN];
    LL base[2];
    LL mod[2];
    void gen(){
        base[0] = 1949313259LL;
        base[1] = 1997293877LL;
        mod[0]  = 2091573227LL;
        mod[1]  = 2117566807LL;
        for(int j=0;j<2;j++){
            for(int i=0;i<MAXN;i++){
                H[j][i]=R[j][i] = 0LL;
                P[j][i] = 1LL;
            }
        }
        for(int j=0;j<2;j++){
            for(int i=1;i<MAXN;i++){
                P[j][i] = (P[j][i-1] * base[j])%mod[j];
            }
        }
    }
    void make_hash(string &arr){
        int len = arr.size();
        for(int j=0;j<2;j++){
            for (LL i = 1; i <= len; i++)H[j][i] = (H[j][i - 1] * base[j] + arr[i - 1] + 1007) % mod[j];
            for (LL i = len; i >= 1; i--)R[j][i] = (R[j][i + 1] * base[j] + arr[i - 1] + 1007) % mod[j];
        }
    }
    inline LL range_hash(int l,int r,int idx){
        LL hashval = H[idx][r + 1] - ((long long)P[idx][r - l + 1] * H[idx][l] % mod[idx]);
        return (hashval < 0 ? hashval + mod[idx] : hashval);
    }
    inline LL reverse_hash(int l,int r,int idx){
        LL hashval = R[idx][l + 1] - ((long long)P[idx][r - l + 1] * R[idx][r + 2] % mod[idx]);
        return (hashval < 0 ? hashval + mod[idx] : hashval);
    }
    inline LL range_dhash(int l,int r){
        LL x = range_hash(l,r,0);
        return (x<<32)^range_hash(l,r,1);
    }
    inline LL reverse_dhash(int l,int r){
        LL x = reverse_hash(l,r,0);
        return (x<<32)^reverse_hash(l,r,1);
    }
};

DoubleHash DH;

string s;
int n;
int dp[1005];

int fun(int pos)
{
    if(pos>n)
    {
        return 0;
    }
    if(dp[pos]!=-1) return dp[pos];

    int val=1010;
    For(i,pos,n)
    {
        if(DH.range_dhash(pos,i)==DH.reverse_dhash(pos,i))
        {
            int curans=fun(i+1)+1;
            val=min(val,curans);
        }
    }
    return dp[pos]=val;
}

void solve(int casenum)
{
    cin>>s;
    n=sz(s);
    s='_'+s;
    DH.make_hash(s);

    mem(dp,-1);
    cout<<"Case "<<casenum<<": "<<fun(1)<<NL;
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    DH.gen();

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/palindrome-partitioning

*/