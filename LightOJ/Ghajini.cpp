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

const int N = 2e5+10;
int arr[N], treeMin[4*N], treeMax[4*N];
//const LL MOD = 1000000007;

void build1(LL node, LL b, LL e)
{
    if(b==e)
    {
        treeMin[node] = arr[b];
        return;
    }

    LL mid = (b + e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    build1(left,b,mid);
    build1(right,mid+1,e);

    treeMin[node] = min(treeMin[left],treeMin[right]);
}

void build2(LL node, LL b, LL e)
{
    if(b==e)
    {
        treeMax[node] = arr[b];
        return;
    }

    LL mid = (b + e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    build2(left,b,mid);
    build2(right,mid+1,e);

    treeMax[node] = max(treeMax[left],treeMax[right]);
}

int query1(LL node, LL b, LL e, LL i, LL j)
{
    if(b > j or e < i) return PINF;
    if(b >= i and e <= j)
    {
        return treeMin[node];
    }

    LL mid = (b + e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    LL p = query1(left,b,mid,i,j);
    LL q = query1(right,mid+1,e,i,j);

    return min(p,q);
}

int query2(LL node, LL b, LL e, LL i, LL j)
{
    if(b > j or e < i) return 0;
    if(b >= i and e <= j)
    {
        return treeMax[node];
    }

    LL mid = (b + e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    LL p = query2(left,b,mid,i,j);
    LL q = query2(right,mid+1,e,i,j);

    return max(p,q);
}

int main()
{
    int t;
    sfi(t);
    For(tt,1,t)
    {
        int n,d;
        sfi2(n,d);
        For(i,1,n) sfi(arr[i]);
        build1(1,1,n);
        build2(1,1,n);

        printf("Case %d: ", tt);
        int maxi = 0;
        for(int i = 1; i<=n and (i+d)-1<=n; i++)
        {
            int ans1 = query1(1,1,n,i,((i+d)-1));
            int ans2 = query2(1,1,n,i,((i+d)-1));
            maxi = max(maxi,abs(ans1-ans2));
        }

        printf("%d\n", maxi);
    }
    //main();
}

/*

*/

