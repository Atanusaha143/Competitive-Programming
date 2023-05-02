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

const int N = 100 + 10;
const int MOD = 1000000007;

int n,money_arr[N],clr;
double p,probability_arr[N];
double dp[N][10005];
int visited[N][10005];

double fun(int pos,int cur_money)
{
    if(pos>n)
    {
        if(cur_money==0) return 1.00;
        return 0.00;
    }
    if(visited[pos][cur_money]==clr) return dp[pos][cur_money];
    visited[pos][cur_money]=clr;

    double val=0.00;
    if(cur_money-money_arr[pos]>=0)
    {
        val=max(val,fun(pos+1,cur_money-money_arr[pos])*(1.00-probability_arr[pos]));
    }
    val=max(val,fun(pos+1,cur_money));

    return dp[pos][cur_money]=val;
}

void solve(int casenum)
{
    cin>>p>>n;
    int total=0;
    For(i,1,n)
    {
        cin>>money_arr[i]>>probability_arr[i];
        total+=money_arr[i];
    }

    clr++;
    cout<<"Case "<<casenum<<": ";
    Rof(i,total,0)
    {
        double curprob=1-fun(1,i);
        if(curprob<p)
        {
            cout<<i<<NL;
            break;
        }
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

Link : https://lightoj.com/problem/just-another-robbery

Sol : We have calculated the probability if we want to make X money. If the probability 
satisfy our condition then X is our answer. 
Basically we calculated what is the probability not to get caught which can be 
found using the formula Y=1-current_probability. 
Now we can say that 1-Y is the probability to get caught. So the more we maximize Y, 
the more the probability of getting caught decreases.

*/