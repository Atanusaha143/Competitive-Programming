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

int n;
int arr[N],brr[N],lis[N];
int tree[4*N],lazy[4*N];

void update(int node, int b, int e, int i, int val)
{
    if(b>i or e<i) return;
    if(b==e and b==i)
    {
        tree[node]=val;
        return;
    }
    int mid=(b+e)>>1;
    int left=node*2;
    int right=left+1;
    if(i<=mid) update(left,b,mid,i,val);
    else update(right,mid+1,e,i,val);
    tree[node]=max(tree[left],tree[right]);
}

int query(int node, int b, int e, int i, int j)
{
    if(b>j or e<i) return 0;
    if(b>=i and e<=j) return tree[node];
    int mid=(b+e)>>1;
    int left=2*node;
    int right=left+1;
    int p=query(left,b,mid,i,j);
    int q=query(right,mid+1,e,i,j);
    return max(p,q);
}

void solve(int casenum)
{
    cin>>n;
    For(i,1,n)
    {
        cin>>arr[i];
        brr[i]=arr[i];
    }

    sort(brr+1,brr+n+1);
    map<LL,int>compress;
    int maxi=0;
    For(i,1,n)
    {
        compress[brr[i]]=i;
        maxi=max(maxi,compress[brr[i]]);
    }

    Rof(i,n,1)
    {
        lis[i]=query(1,1,maxi,compress[arr[i]]+1,maxi)+1;
        update(1,1,maxi,compress[arr[i]],lis[i]);
    }

    cout<<*max_element(lis+1,lis+n+1);
} 

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*
https://cses.fi/problemset/task/1145/
*/
