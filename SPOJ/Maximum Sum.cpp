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

const int N = 5e5+10;
LL arr[N], tree[4*N];
//const LL MOD = 1000000007;

void build(LL node, LL b, LL e)
{
    if(b==e)
    {
        tree[node] = b;
        return;
    }

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    build(left,b,mid);
    build(right,mid+1,e);

    if(arr[tree[left]] > arr[tree[right]]) tree[node] = tree[left];
    else tree[node] = tree[right];
}

void update(LL node, LL b, LL e, LL i, LL value)
{
    if(b > i or e < i) return;
    if(b == e and b == i)
    {
        tree[node] = i;
        arr[i] = value;
        return;
    }

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    if(mid >= i) update(left,b,mid,i,value);
    else update(right,mid+1,e,i,value);

    if(arr[tree[left]] > arr[tree[right]]) tree[node] = tree[left];
    else tree[node] = tree[right];
}

LL query(LL node, LL b, LL e, LL i, LL j)
{
    if(b > j or e < i) return -1;
    if(b >= i and e <= j) return tree[node];

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    LL p = query(left,b,mid,i,j);
    LL q = query(right,mid+1,e,i,j);

    if(arr[p] > arr[q]) return p;
    else return q;
}

int main()
{
    int n;
    sfi(n);
    For(i,1,n) sfl(arr[i]);
    build(1LL,1LL,n);
    int q;
    sfi(q);
    while(q--)
    {
        char x;
        cin>>x;
        if(x == 'Q')
        {
            LL a,b;
            sfl2(a,b);
            LL ans = query(1LL,1LL,n,a,b);
            LL max1 = arr[ans];
            LL ans1 = query(1LL,1LL,n,a,ans-1);
            LL ans2 = query(1LL,1LL,n,ans+1,b);
            LL max2 = max(arr[ans1],arr[ans2]);
            printf("%lld\n", max1+max2);
        }
        else
        {
            LL i,val;
            sfl2(i,val);
            update(1LL,1LL,n,i,val);
        }
    }
    //main();
}

/*


*/

