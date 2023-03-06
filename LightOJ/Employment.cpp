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

const int N = 200 + 10;
const int MOD = 1000000007;

int n;
int mPrefer[N][N],wPrefer[N][N],wPartner[N],mRank[N][N];

void genRank()
{
    for(int i=n+1; i<=2*n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int m=wPrefer[i][j];
            // for ith woman, the rank of man m is j
            mRank[i][m]=j;
        }
    }
}

void genStableMarriage()
{
    genRank();
    
    stack<int>freemen;
    for(int i=1; i<=n; i++) freemen.push(i);
    while (!freemen.empty())
    {
        // Pick the first free man who is not engaged yet
        int m=freemen.top();

        // One by one go to all women according to m's preferences.
        // Here m is the picked free man
        for(int i=1; i<=n; i++)
        {
            int w=mPrefer[m][i];
            // w is free, hence w and m become partners
            // Note that the partnership maybe changed later. 
            // So we can say they are engaged not married
            if(wPartner[w]==0)
            {
                wPartner[w]=m;
                freemen.pop();
                break;
            }
            else // If w is not free
            {
                // m1 is the current partner of w
                int m1=wPartner[w];
                // If w prefers m over m1,
                // then break the engagement between w and m1 and
                // engage m with w.
                if(mRank[w][m]<mRank[w][m1])
                {
                    wPartner[w]=m;
                    freemen.pop();
                    freemen.push(m1);
                    break;
                }
            }
        }
    }
}

void printSolution(int casenum)
{
    cout<<"Case "<<casenum<<": ";
    for(int i=n+1; i<=2*n; i++)
    {
        cout<<"("<<wPartner[i]<<" "<<i<<") ";
    }
    cout<<NL;
}

void clean(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            mPrefer[i][j]=0;
        }
    }
    for(int i=n+1; i<=2*n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            wPrefer[i][j]=0;
            mRank[i][j]=0;
        }
        wPartner[i]=0;
    }
}

void solve(int casenum)
{
    cin>>n;

    clean(n);

    /// Assuming stuednts = men, company = women
    /// Alwasy take the size 2*N

    // 1 to n = men
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>mPrefer[i][j];
        }
    }
    // n+1 to 2*n = women
    for(int i=n+1; i<=2*n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>wPrefer[i][j];
        }
    }

    genStableMarriage();
    printSolution(casenum);
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

Link : https://lightoj.com/problem/employment

*/
