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

const int N = 1e5 + 10;
const int MOD = 1000000007;

LL n,q;
LL arr[N], brr[N];
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
    int i=0, j=0;
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
    for(int i=0; i<sz(node); i++)
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

LL findResult(vector<info>&vec, LL k)
{
    int l=0, r=sz(vec)-1, mid, ans=-1;
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
        LL totallensum=(ans+1)*k;
        LL curlensum=vec[ans].sum;
        res=totallensum-curlensum;
    }
    l=0, r=sz(vec)-1, mid, ans=-1;
    while (l<=r)
    {
        mid=l+(r-l)/2LL;
        if(vec[mid].val>k)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    if(ans!=-1)
    {
        LL totallen=sz(vec)-ans;
        LL totallensum=(totallen*k);
        LL curlensum=0;
        if(ans!=0)
        {
            curlensum=vec[sz(vec)-1].sum-vec[ans-1].sum;
        }
        else
        {
            curlensum=vec[sz(vec)-1].sum;
        }
        res+=(curlensum-totallensum);
    }
    return res;
}

LL query(int node, int b, int e, int i, int j, LL k)
{
    if(b>j or e<i) return 0;
    if(b>=i and e<=j)
    {
        LL ans=findResult(tree[node],k);
        return ans;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    LL p=query(left,b,mid,i,j,k);
    LL q=query(right,mid+1,e,i,j,k);
    return (LL)(p+q);
}

void solve(int casenum)
{
    cin>>n;
    For(i,1,n)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    cin>>q;
    LL l,r,k;
    cout<<"Case "<<casenum<<":"<<NL;
    For(i,1,q)
    {
        cin>>l>>r>>k;
        LL ans=query(1,1,n,l,r,k);
        cout<<ans<<NL;
    }

    For(i,1,4*N)
    {
        tree[i].clear();
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

https://toph.co/p/a-super-easy-problem---array-query

*/
