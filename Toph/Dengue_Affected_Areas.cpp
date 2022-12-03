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

int n,m,mini,maxi;
int arr[N];
vector<int>tree[4*N];

void combine(vector<int>&node, vector<int>&left, vector<int>&right)
{
    int leftsize=sz(left), rightsize=sz(right);
    int i=0,j=0;
    while (i<leftsize and j<rightsize)
    {
        if(left[i]<right[j])node.PB(left[i]),i++;
        else node.PB(right[j]),j++;
    }
    while (i<leftsize)
    {
        node.PB(left[i]);
        i++;
    }
    while (j<rightsize)
    {
        node.PB(right[j]);
        j++;
    }
}

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].PB(arr[b]);
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    build(left,b,mid);
    build(right,mid+1,e);
    combine(tree[node],tree[left],tree[right]);
}

PII searchans(vector<int>&vec, int p, int q)
{
    int l=0,r=sz(vec)-1,mid,ansl=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(vec[mid]>=p)
        {
            r=mid-1;
            ansl=mid;
        }
        else l=mid+1;
    }
    l=0,r=sz(vec)-1;
    int ansr=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(vec[mid]<=q)
        {
            l=mid+1;
            ansr=mid;
        }
        else r=mid-1;
    }
    return PII(ansl,ansr);
}

int query(int node, int b, int e, int i, int j, int p, int q)
{
    if(b>j or e<i) return 0;
    if(b>=i and e<=j)
    {
        PII ans=searchans(tree[node],p,q);
        int l=ans.first;
        int r=ans.second;
        int res=0;
        if(l<=r and l!=-1 and r!=-1)
        {
            res=r-l+1;
            maxi=max(maxi,tree[node][r]);
            mini=min(mini,tree[node][l]);
        }
        return res;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    int x=query(left,b,mid,i,j,p,q);
    int y=query(right,mid+1,e,i,j,p,q);
    return (x+y);
}

void solve(int casenum)
{
    cin>>n>>m;
    For(i,1,n)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    For(i,1,m)
    {
        int l,r,p,q;
        cin>>l>>r>>p>>q;
        mini=PINF;
        maxi=0;
        int ans=query(1,1,n,l,r,p,q);
        if(ans==0)
        {
            cout<<"0 -1 -1"<<NL;
            continue; 
        }
        cout<<ans<<" "<<mini<<" "<<maxi<<NL;
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

https://toph.co/p/dengue-affected-areas

*/
