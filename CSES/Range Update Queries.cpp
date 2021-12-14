#include <bits/stdc++.h>
using namespace std;

#define NL              '\n'
#define sz(x)           x.size()
#define PINF            INT_MAX
#define NINF            INT_MIN
#define PI              (2.0*acos(0.0))

#define sfi(x)          scanf("%d",&x)
#define sfi2(x,y)       scanf("%d %d",&x,&y)
#define sfi3(x,y,z)     scanf("%d %d %d",&x,&y,&z)
#define sfl(x)          scanf("%lld",&x)
#define sfl2(x,y)       scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z)     scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x)          scanf("%lf",&x);
#define sfd2(x,y)       scanf("%lf %lf",&x,&y);

#define max3(a,b,c)     max(a,max(b,c))
#define max4(a,b,c,d)   max(max3(a,b,c),d)
#define min3(a,b,c)     min(a,min(b,c))
#define min4(a,b,c,d)   min(a,min3(b,c,d))

#define PB              push_back
#define MP              make_pair
#define For(i, j, k)    for(int i = j; i <= k; i++)
#define Rof(i, j, k)    for(int i = j; i >= k; i--)
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define now             cout<<"Here"<<NL;

#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define READ            freopen("input.txt","r",stdin)
#define WRITE           freopen("output.txt","w",stdout)
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

LL gcd(LL a,LL b) { return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a,LL b) { return (a/gcd(a,b))*b; }

LL power_mod(LL base, LL power, LL mod)
{
    if(power==0) return 1LL;
    else if(power%2LL == 1)
    {
        LL p1 = base % mod;
        LL p2 = (power_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2LL == 0)
    {
        LL p1 = (power_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}

// Grid direction array [4]
int X[4]= {0,0,-1,1};
int Y[4]= {1,-1,0,0};
// Grid direction array [8]
int X8[8]= {0,0,1,-1,-1,1,1,-1};
int Y8[8]= {1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

inline bool checkBit(int N, int pos){return (bool)(N & (1 << pos));}
inline int setBit(int N, int pos) { return N = N | (1 << pos); }

const int N = 2e5 + 10;
LL arr[N], tree[4*N], lazy[4*N];
//const LL MOD = 1000000007;

void build(LL node, LL b, LL e)
{
    if(b == e)
    {
        tree[node] = arr[e];
        return;
    }

    LL mid = (b + e) / 2LL;
    LL left = node * 2LL;
    LL right = left + 1;

    build(left,b,mid);
    build(right,mid+1,e);

    tree[node] = tree[left] + tree[right];
}

void update(LL node, LL b, LL e, LL i, LL j, LL val)
{
    LL mid = (b+e)/2LL;
    LL left = node * 2LL;
    LL right = left + 1;

    if(lazy[node])
    {
        LL temp = lazy[node];
        lazy[node] = 0;
        tree[node] += (LL)(temp * (e - b + 1));
        if(b!=e)
        {
            lazy[left] += temp;
            lazy[right] += temp;
        }
    }

    if(b > j or e < i) return;
    if(b >= i and e <= j)
    {
        LL temp = (LL)((e - b + 1) * val);
        tree[node] += temp;
        if(b!=e)
        {
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }

    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);

    tree[node] = tree[left] + tree[right];
}

LL query(LL node, LL b, LL e, LL i, LL j)
{
    LL mid = (b+e)/2LL;
    LL left = node * 2;
    LL right = left + 1;

    if(lazy[node])
    {
        LL temp = lazy[node];
        lazy[node] = 0;
        tree[node] += (LL)(temp * (e - b + 1));
        if(b!=e)
        {
            lazy[left] += temp;
            lazy[right] += temp;
        }
    }

    if(b > j or e < i) return 0;
    if(b >= i and e <= j) return tree[node];

    LL p = query(left,b,mid,i,j);
    LL q = query(right,mid+1,e,i,j);

    return (LL)(p+q);
}


int main()
{
//    int t; sfi(t); For(tt,1,t) {

        LL n, q;
        sfl2(n,q);
        for(int i=1; i<=n; i++) sfl(arr[i]);
        build(1LL,1LL,n);

        while(q--)
        {
            LL x;
            sfl(x);
            if(x == 1) // update
            {
                LL l, r, val;
                sfl3(l,r,val);
                update(1LL,1LL,n,l,r,val);
            }
            else if(x == 2) // query
            {
                LL i;
                sfl(i);
                LL ans = query(1LL,1LL,n,i,i);
                printf("%lld\n",ans);
            }
        }

//    }
}

/*

*/





