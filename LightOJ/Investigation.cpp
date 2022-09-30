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

const int N = 1e6 + 10;
const int MOD = 1000000007;

int l, r, k, clr;
string str;
LL dp[10][2][85][85], visited[10][2][85][85];

LL fun(int pos, int is_small, int digit_sum, int mod_val)
{
    if(pos >= str.size())
    {
        if((digit_sum % k) == 0 and mod_val == 0) return 1;
        return 0;
    }
    if(visited[pos][is_small][digit_sum][mod_val] == clr) return dp[pos][is_small][digit_sum][mod_val];
    visited[pos][is_small][digit_sum][mod_val] = clr;

    LL val = 0, lo = 0, hi = str[pos]-'0';
    if(is_small) hi = 9;

    for(int i=lo; i<=hi; i++)
    {
        int new_is_small = is_small | (i < hi);
        val += fun( pos+1,new_is_small,digit_sum+i,((mod_val*10)+i)%k );
    }
    return dp[pos][is_small][digit_sum][mod_val] = val;
}

void solve(int casenum)
{

    cin>>l>>r>>k;

    cout<<"Case "<<casenum<<": ";
    if(k >= 85) cout<<"0"<<endl;
    else
    {
        string str1 = to_string(l-1);
        string str2 = to_string(r);
        
        clr++;
        str = str1;
        LL ansl = fun(0,0,0,0);

        clr++;
        str = str2;
        LL ansr = fun(0,0,0,0);

        LL ans = ansr - ansl;
        cout<<ans<<endl;
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
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/investigation

Sol : We will consider those number as answer if a number holds the following conditions:
1) digit sum will be divisible by k
2) the number will be divisible by k

As there will be atmost 10 digits for the highest number
and the first digit can be at most 2 and the 
others are 9, so the digit sum will be maximum 83. To satisfy both the above condition in each
step, we will need the mod value at most 83. 

*/

