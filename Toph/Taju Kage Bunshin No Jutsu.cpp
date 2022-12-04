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

const int N = 2e5 + 10;
const int MOD = 1000000007;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// *find_by_order = value of an index, order_of_key = index of a value where it should be
typedef tree<PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n,q;
int arr[N];
ordered_set ost[4*N];

void combine(ordered_set &node, ordered_set &left, ordered_set &right)
{
    for(PII x:left) node.insert(x);
    for(PII x:right) node.insert(x);
}

void build(int node, int b, int e)
{
    if(b==e)
    {
        ost[node].insert({arr[e],e});
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    build(left,b,mid);
    build(right,mid+1,e);
    combine(ost[node],ost[left],ost[right]);
}

void update(int node, int b, int e, int i, PII del, PII add)
{
    ost[node].erase(del);
    ost[node].insert(add);
    if(b==e)
    {
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    if(i<=mid) update(left,b,mid,i,del,add);
    else update(right,mid+1,e,i,del,add);
}

int query(int node, int b, int e, int i, int j, PII val)
{
    if(b>j or e<i) return 0;
    if(b>=i and e<=j)
    {
        int res=ost[node].order_of_key(val);
        return res;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    int p=query(left,b,mid,i,j,val);
    int q=query(right,mid+1,e,i,j,val);
    return p+q;
}

void solve(int casenum)
{
    cin>>n;
    int limit=2e5;
    For(i,1,limit)arr[i]=PINF;
    For(i,1,n)
    {
        cin>>arr[i];
    }
    build(1,1,limit);

    cin>>q;
    while (q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int val;
            cin>>val;
            n++;
            update(1,1,limit,n,PII(arr[n],n),PII(val,n));
            arr[n]=val;
        }
        else if(type==2)
        {
            update(1,1,limit,n,PII(arr[n],n),PII(PINF,n));
            n--;
        }
        else
        {
            int b,e,k;
            cin>>b>>e>>k;
            int l=1, r=1e9, mid, ans=0;
            int tempk=(e-b+1)-k+1; // tempkth element if we sort in ascending order
            while (l<=r)
            {
                mid=l+(r-l)/2;
                int somanBachoto=query(1,1,limit,b,e,PII(mid,PINF));
                if(somanBachoto>=tempk)
                {
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            cout<<ans<<NL;
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
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://toph.co/p/taju-kage-bunshin-no-jutsu
Sol : Merge sort tree with update using PBDS.
Build : Build the full tree((n+q) nodes) at a time 
Update : Each time if we have an Add operation, we are erasing the previous 
nth value(an INT_MAX value was added at the time of constructing the tree) and 
adding the current value to the nth position.
Each time we are doing a Delete operation, we are erasing the previous 
nth value and adding a maximum value(an INT_MAX value which was removed at the time
of inserting the nth value)
Query : If b and e are begining and ending of the searching range then (e-b+1)-k+1 th 
is the kth element if we sort in ascending order. Let x is the kth element. If it is so
then x will have exactly k-1 smaller elements. A binary search will be able to handle 
this scenario.

*/