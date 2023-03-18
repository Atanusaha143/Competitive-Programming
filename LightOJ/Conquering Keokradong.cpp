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

int n,k,maxi;
int arr[N], brr[N];

bool possible(int mid)
{
    int cur_val=0,cur_k=0;
    For(i,1,n)
    {
        if(arr[i]>mid) return false;
        if(cur_val+arr[i]==mid)
        {
            cur_k++;
            cur_val=0;
        }
        else if(cur_val+arr[i]>mid)
        {
            cur_k++;
            cur_val=arr[i];
        }
        else cur_val+=arr[i];
    }
    if(cur_val) cur_k++;
    return (cur_k<=k+1);
}

void show(int maxi)
{
    vector<int>ans;
    int cur_val=0,cur_k=0;
    For(i,1,n)
    {
        if(cur_val+arr[i]==maxi)
        {
            ans.PB(maxi);
            cur_val=0;
            cur_k++;
            continue;
        }
        else if(cur_val+arr[i]>maxi)
        {
            ans.PB(cur_val);
            cur_k++;
            cur_val=arr[i];
            continue;
        }
        else cur_val+=arr[i];

        int baki=n-i+1;
        int lage=k-cur_k+1;
        if(baki==lage)
        {
            ans.PB(cur_val);
            For(j,i+1,n) ans.PB(arr[j]);
            break;
        }
    }
    cout<<maxi<<NL;
    for(auto x:ans) cout<<x<<NL;
}

void solve(int casenum)
{
    cin>>n>>k;
    n++;
    For(i,1,n)
    {
        cin>>arr[i];
    }

    int l=1,r=1e9,mid,ans=-1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if(possible(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<"Case "<<casenum<<": ";
    show(ans);
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
Link : https://lightoj.com/problem/conquering-keokradong

Sol : Binary search on answer.
Let's say we fixed a value d and we are determined that every day we won't walk more than d miles.
So if we walk d miles each day then is it possible to stop at k camps? From here we can smell binary search.
Validate for each d if it is possible to stop at k camps. If possible then decrease the value of d
otherwise increase increase the value of d.
Then just print k+1 values which are <=d.

*/
