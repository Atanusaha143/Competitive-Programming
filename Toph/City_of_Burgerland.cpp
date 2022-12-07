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

int n,m;
LL arr[N];

struct info
{
    LL val, sum;
    info(LL val, LL sum)
    {
        this->val=val;
        this->sum=sum;
    }
};

vector<info>tree[4*N];
void combine(vector<info>&node, vector<info>&left, vector<info>&right)
{
    int leftlen=sz(left), rightlen=sz(right);
    int i=0,j=0;
    while (i<leftlen and j<rightlen)
    {
        if(left[i].val<right[j].val)
        {
            node.PB(left[i]);
            i++;
        }
        else
        {
            node.PB(right[j]);
            j++;
        }
    }
    while (i<leftlen)
    {
        node.PB(left[i]);
        i++;
    }
    while (j<rightlen)
    {
        node.PB(right[j]);
        j++;
    }
    for(i=0; i<sz(node); i++)
    {
        if(i==0)
        {
            node[i].sum=node[i].val;
        }
        else
        {
            node[i].sum=node[i].val+node[i-1].sum;
        }
    }
}

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].PB(info(arr[e],arr[e]));
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    build(left,b,mid);
    build(right,mid+1,e);
    combine(tree[node],tree[left],tree[right]);
}

LL search(vector<info>&vec, LL k)
{
    LL l=0, r=sz(vec)-1, mid, ans=-1;
    while (l<=r)
    {
        mid=l+(r-l)/2LL;
        if(vec[mid].val<k)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    LL res=0;
    if(ans!=-1)
    {
        LL val=vec[ans].sum;
        LL valhowarkotha=1LL*(ans+1)*k;
        res=valhowarkotha-val;
    }
    return res;
}

LL query(int node, int b, int e, int i, int j, int k)
{
    if(b>j or e<i) return 0;
    if(b>=i and e<=j)
    {
        LL ans=search(tree[node],k);
        return ans;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    LL p=query(left,b,mid,i,j,k);
    LL q=query(right,mid+1,e,i,j,k);
    return (LL)p+q;
}

void solve(int casenum)
{
    cin>>n>>m;
    For(i,1,n)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    int l,r,k;
    For(i,1,m)
    {
        cin>>l>>r>>k;
        LL qans=query(1,1,n,l,r,k);
        cout<<qans<<NL;
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
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://toph.co/p/city-of-burgerland
Sol : For each node create a cumulative sum array which will tell us the sum till x'th position.
Now let's say there are m elements which are less than k. So total increament required to make those 
elements equal to k is : (m*k)-(sum of those m elements)


*/