#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define endl              '\n'
#define sz(x)           x.size()
#define PINF            INT_MAX
#define NINF            INT_MIN
#define PI              (2.0*acos(0.0))
#define PB              push_back
#define MP              make_pair
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
#define now             cout<<"Here"<<endl;
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define READ            freopen("input.txt","r",stdin)
#define WRITE           freopen("output.txt","w",stdout)
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// *find_by_order = value of an index, order_of_key = index of a value where it should be
//typedef tree<PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

//LL power_mod(LL base, LL power, LL mod){
//    if(power==0) return 1LL;
//    else if(power%2LL == 1){
//        LL p1 = base % mod; LL p2 = (power_mod(base,power-1,mod))%mod;
//        p1 = (LL)(p1*p2); return p1%mod;
//    }
//    else if(power%2LL == 0){
//        LL p1 = (power_mod(base,power/2LL,mod))%mod; p1 = (LL)(p1*p1);
//        return p1%mod;
//    }
//}

//LL original_power(LL base, LL power){
//    if(power==0) return 1LL;
//    else if(power%2LL == 1){
//        LL p1 = base; LL p2 = (original_power(base,power-1));
//        p1 = (LL)(p1*p2); return p1;
//    }
//    else if(power%2LL == 0){
//        LL p1 = (original_power(base,power/2LL)); p1 = (LL)(p1*p1);
//        return p1;
//    }
//}

//// Grid direction array [4]
//int X[4]= {0,0,-1,1};
//int Y[4]= {1,-1,0,0};
// Grid direction array [8]
//int X8[8]= {0,0,1,-1,-1,1,1,-1};
//int Y8[8]= {1,-1,0,0,-1,-1,1,1};
//// Knight Direction Array
//int KX[8] = {1,1,2,2,-1,-1,-2,-2};
//int KY[8] = {2,-2,1,-1,2,-2,1,-1};

///------------------------------------------------------------------------------------------------------

const int N = 1e5 + 10;
const int MOD = 1000000007;

int n, q;
int arr[N];

struct info{
    int bits[28];
};
info tree[4*N];

inline void build(int node, int b, int e)
{
    if(b == e)
    {
        for(int i=0; i<=27; i++)
        {
            int bit = (int)checkBit(arr[e],i);
            tree[node].bits[i] = bit;
        }
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left + 1;

    build(left,b,mid);
    build(right,mid+1,e);

    for(int i=0; i<=27; i++)
    {
        tree[node].bits[i] = tree[left].bits[i] + tree[right].bits[i];
    }
}

inline void update(int node, int b, int e, int pos, int value)
{
    if(b == e)
    {
        for(int i=0; i<=27; i++)
        {
            int bit = (int)checkBit(value,i);
            tree[node].bits[i] = bit;
        }
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left + 1;

    if(pos <= mid) update(left,b,mid,pos,value);
    else update(right,mid+1,e,pos,value);

    for(int i=0; i<=27; i++)
    {
        tree[node].bits[i] = tree[left].bits[i] + tree[right].bits[i];
    }
}

inline info query(int node, int b, int e, int i, int j)
{
    if(b > j or e < i) return tree[0];
    if(b >= i and e <= j) return tree[node];

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left + 1;

    info p = query(left,b,mid,i,j);
    info q = query(right,mid+1,e,i,j);
    info x;
    for(int i=0; i<=27; i++)
    {
        x.bits[i] = p.bits[i] + q.bits[i];
    }
    return x;
}

inline void solve(int casenum)
{
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    build(1,1,n);

    for(int j=1; j<=q; j++)
    {
        int type;
        cin>>type;
        if(type == 1)
        {
            int pos, val;
            cin>>val>>pos;
            update(1,1,n,pos,val);
        }
        else
        {
            string str;
            cin>>str;
            int l, r;
            cin>>l>>r;
            if(str == "OR")
            {
                LL sum = 0;
                info range_bits = query(1,1,n,l,r);
                for(LL i=0; i<=27; i++)
                {
                    int on_bits = range_bits.bits[i];
                    if(on_bits > 0)
                    {
                        LL pairs_with_on_bits = (1LL * on_bits * (on_bits - 1)) / 2LL;
                        int off_bits = ((r-l)+1) - on_bits;
                        LL pairs_with_on_and_off_bits = (1LL * on_bits * off_bits);
                        sum = sum + (1LL * (1LL << (LL)i) * pairs_with_on_bits) + (1LL * (1LL << (LL)i) * pairs_with_on_and_off_bits);
                    }
                }
                cout<<sum<<endl;
            }
            else if(str == "AND")
            {
                LL sum = 0;
                info range_bits = query(1,1,n,l,r);
                for(LL i=0; i<=27; i++)
                {
                    int on_bits = range_bits.bits[i];
                    if(on_bits > 0)
                    {
                        LL pairs_with_on_bits = (1LL * on_bits * (on_bits - 1)) / 2;
                        sum = sum + (1LL * (1LL << (LL)i) * pairs_with_on_bits);
                    }
                }
                cout<<sum<<endl;
            }
            else
            {
                LL sum = 0;
                info range_bits = query(1,1,n,l,r);
                for(LL i=0; i<=27; i++)
                {
                    int on_bits = range_bits.bits[i];
                    if(on_bits > 0)
                    {
                        int off_bits = ((r-l)+1) - on_bits;
                        LL pairs_with_on_and_off_bits = (1LL * on_bits * off_bits);
                        sum = sum + (1LL * (1LL << (LL)i) * pairs_with_on_and_off_bits);
                    }
                }
                cout<<sum<<endl;
            }
        }
    }
}

int main()
{
    IOS;

//    READ;
//    WRITE;

    int t = 1;
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*
https://www.spoj.com/problems/SUMSUM/
*/

