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

///-----------------------------------------------------------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------------------------------------------

const int N = 1e6 + 10;
const int MOD = 1000000007;

LL l, r;
string str, str1, str2;
LL dp1[12][2][2], dp2[12][2];

LL fun2(int pos, int is_small)
{
    if(pos >= str.size()) return 1;
    if(dp2[pos][is_small] != -1) return dp2[pos][is_small];

    LL val = 0, lo = 0, hi = str[pos] - '0';
    if(is_small) hi = 9;

    for(int i=lo; i<=hi; i++)
    {
        int new_is_small = is_small | (i < hi);
        val += fun2( pos+1,new_is_small );
    }
    return dp2[pos][is_small] = val; 
}

LL fun1(int pos, int is_small, int has_started)
{
    if(pos >= str.size()) return 0;
    if(dp1[pos][is_small][has_started] != -1) return dp1[pos][is_small][has_started];

    LL val = 0, lo = 0, hi = str[pos] - '0';
    if(is_small) hi = 9; /// if the current number is smaller than the original number then we can place any digit

    for(int i=lo; i<=hi; i++)
    {
        int new_is_small = is_small | (i < hi);
        int new_has_started = has_started | (i != 0);
        val += fun1( pos+1,new_is_small,new_has_started );
        if(has_started and i == 0)
        {
            val += fun2( pos+1,new_is_small );
        }
    }
    return dp1[pos][is_small][has_started] = val;
}

void solve(int casenum)
{

    cin>>l>>r;
    str1 = to_string(l-1);
    str2 = to_string(r);
    
    mem(dp1,-1);
    mem(dp2,-1);
    str = str1;
    LL ansl = fun1(0,0,0);

    mem(dp1,-1);
    mem(dp2,-1);
    str = str2;
    LL ansr = fun1(0,0,0);

    LL ans = ansr - ansl;
    if(l == 0) ans++;

    cout<<"Case "<<casenum<<": "<<ans<<endl;
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

Link : https://lightoj.com/problem/how-many-zeroes

Sol : If we put a zero in a particular position then by fun2 we counting 
how many numbers will contain this zero after this.

*/