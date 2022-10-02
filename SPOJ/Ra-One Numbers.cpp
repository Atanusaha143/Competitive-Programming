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

int l, r, clr;
string str;

LL dp[10][10][2][2][50][50], visited[10][10][2][2][50][50];

LL fun(int pos, int cur_idx, int is_small, int has_started, int odd_digit_sum, int even_digit_sum)
{

    if(pos >= str.size())
    {
        if(has_started and cur_idx > 1)
        {
            int dif = even_digit_sum - odd_digit_sum;
            if(dif == 1) return 1;
        }
        return 0;
    }
    if(visited[pos][cur_idx][is_small][has_started][odd_digit_sum][even_digit_sum] == clr)
        return dp[pos][cur_idx][is_small][has_started][odd_digit_sum][even_digit_sum];
    visited[pos][cur_idx][is_small][has_started][odd_digit_sum][even_digit_sum] = clr;

    LL val = 0, lo = 0, hi = str[pos] - '0';
    if(is_small) hi = 9;

    for(int i=lo; i<=hi; i++)
    {
        int new_is_small = is_small | (i < hi);
        int new_has_started = has_started | (i != 0);
        int new_cur_idx = cur_idx;
        int new_odd_digit_sum = odd_digit_sum;
        int new_even_digit_sum = even_digit_sum;

        if(new_has_started)
        {
            if(!has_started)
            {
                int max_digit = (str.size() - pos);
                if(max_digit % 2) new_cur_idx += 1;
            }
            if(new_cur_idx % 2) new_odd_digit_sum += i;
            else new_even_digit_sum += i;
            new_cur_idx += 1;
        }
        val += fun( pos+1,new_cur_idx,new_is_small,new_has_started,new_odd_digit_sum,new_even_digit_sum );
    }
    return dp[pos][cur_idx][is_small][has_started][odd_digit_sum][even_digit_sum] = val;
}

void solve(int casenum)
{

    cin>>l>>r;
    string str1 = to_string(l-1);
    string str2 = to_string(r);

    clr++;
    str = str1;
    LL ansl = fun(0,0,0,0,0,0);

    clr++;
    str = str2;
    LL ansr = fun(0,0,0,0,0,0);

    LL ans = ansr - ansl;
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

Link : https://www.spoj.com/problems/RAONE/

Sol : 

Indexing starts from 1, from right to left.
Example:
+) 123
    location 1 : 3
    location 2 : 2
    location 3 : 1
+) 1234
    location 1 : 4
    location 2 : 3
    location 3 : 2
    location 4 : 1

We can see that if the number length is even then it is okay to start from left to right
by maintaining 0 based indexing but if the length is odd then we have to start from left to 
right by maintaining 1 based indexing.

We just convert the right to left indexing into left to right indexing.

Others are just normal digit dp solution.

*/