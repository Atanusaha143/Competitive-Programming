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

LL l, r;
string str;
LL dp1[20][20][2][2][2];

LL fun1(int pos, int idx, int is_small, int has_started, int is_boaring)
{
    if(pos >= str.size())
    {
        if(has_started and !is_boaring) return 1;
        return 0;
    }
    if(dp1[pos][idx][is_small][has_started][is_boaring] != -1) return dp1[pos][idx][is_small][has_started][is_boaring];

    LL val = 0, lo = 0, hi = str[pos] - '0';
    if(is_small) hi = 9;

    for(int i=lo; i<=hi; i++)
    {
        int new_is_small = is_small | (i < hi);
        int new_has_started = has_started | (i != 0);
        int cur_idx = idx;
        int bored = is_boaring;
        if(new_has_started)
        {
            int x = i % 2;
            int y = cur_idx % 2;
            cur_idx += 1;
            if(x != y)
            {
                bored &= 0;
            }
            
        }
        val += fun1( pos+1,cur_idx,new_is_small,new_has_started,bored);
    }
    return dp1[pos][idx][is_small][has_started][is_boaring] = val;
}

void solve(int casenum)
{

    cin>>l>>r;

    cout<<"Case #"<<casenum<<": ";
    string str1 = to_string(l-1);
    string str2 = to_string(r);
    
    mem(dp1,-1);
    str = str1;
    LL ansl = (l+1) - fun1(0,1,0,0,1);

    mem(dp1,-1);
    str = str2;
    LL ansr = (r+1) - fun1(0,1,0,0,1);

    LL ans = (ansr - ansl) + 1;
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

Link : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem

Sol : State description : 

1) pos : current digit position
2) idx : current digit position if we have actually began to build a number
3) is_small : determines if we are in range
4) has_started : determines if we have started building a number
5) is_boaring : determines the current number is boaring

We calculated the numbers which are not boaring then subtract the answer from the
total range numbers.

*/