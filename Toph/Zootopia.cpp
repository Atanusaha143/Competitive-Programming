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

#define deb(x) cerr <<__LINE__<<": "<< #x <<" "; _print(x); cerr << endl;
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

string s;
LL dp[20][515][165];

LL fun(int pos,int small,int sum1,int sum2,int mask)
{
    if(pos>=sz(s))
    {
        if(sum2 and sum1%sum2==0) return 1;
        return 0;
    }
    if(small and dp[pos][mask][sum1]!=-1) return dp[pos][mask][sum1];
    int lo=0,hi=s[pos]-'0';
    if(small) hi=9;
    LL val=0;
    for(int i=lo;i<=hi;i++)
    {
        int newsmall=small|(i<hi);
        bool status=(bool)(mask&(1<<i));
        int newsum1=sum1+i,newsum2=sum2,newmask=mask;
        if(!status)
        {
            newsum2=sum2+i;
            newmask=mask|(1<<i);
        }
        val+=fun(pos+1,newsmall,newsum1,newsum2,newmask);
    }
    if(small) return dp[pos][mask][sum1]=val;
    else return val;
}

string convert(string s)
{
    int need=19-sz(s);
    string temp;
    while (need--) temp.PB('0');
    temp=temp+s;
    return temp;
}

void solve(int casenum)
{
    LL l,r;
    cin>>l>>r;

    s=to_string(l-1);
    s=convert(s);
    LL ansl=fun(0,0,0,0,0);

    s=to_string(r);
    s=convert(s);
    LL ansr=fun(0,0,0,0,0);

    LL ans=ansr-ansl;
    cout<<ans<<NL;
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    mem(dp,-1);

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://toph.co/p/zootopia

Sol : Need masking to count the number of distinct digits.
DP is defined as globally means we will memset dp once and for every case we will use previous 
test case's dp value if all the current test case's states fits. We added another condition "small"
at the time of checking dp. It is an optimization. If in previous case we have calculated from 1 to 5
and currently we need 2 to 4 then it is optimal to use the previous dp answer. To make sure the
answer is correct we need to store dp value like this : 
                if(small) return dp[pos][mask][sum1]=val;

*/