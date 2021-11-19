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

const int N = 1e5 + 10;
int tree[26][4*N];
//const LL MOD = 1000000007;
int n,m;
string str;

void build(int node, int b, int e, int i)
{
    if(b == e)
    {
        if(str[e]-'a' == i) tree[i][node] = 1;
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left + 1;

    build(left,b,mid,i);
    build(right,mid+1,e,i);

    tree[i][node] = tree[i][left] + tree[i][right];
}

void update(int node, int b, int e, int i, int pos, int value)
{
    if(b == e)
    {
        tree[i][node] = value;
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left + 1;

    if(pos <= mid)update(left,b,mid,i,pos,value);
    else update(right,mid+1,e,i,pos,value);

    tree[i][node] = tree[i][left] + tree[i][right];
}

int query(int node, int b, int e, int i, int j, int pos)
{
    if(b > j or e < i) return 0;
    if(b >= i and e <= j) return tree[pos][node];

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left + 1;

    int p = query(left,b,mid,i,j,pos);
    int q = query(right,mid+1,e,i,j,pos);

    return p + q;
}

int main()
{
//    int t; sfi(t); For(tt,1,t){}

    sfi2(n,m);
    cin>>str;

    For(i,0,25) build(1,0,n-1,i);

    while(m--)
    {
        int x;
        sfi(x);

        if(x == 2)
        {
            int l,r;
            sfi2(l,r);
            l--; r--;
            char c;
            cin>>c;
            int i = c - 'a';
            int ans = query(1,0,n-1,l,r,i);
            printf("%d\n", ans);

        }
        else
        {
            int i;
            sfi(i); i--;
            char c;
            cin>>c;
            int preChar = str[i] - 'a';
            update(1,0,n-1,preChar,i,0);
            int currChar = c - 'a';
            update(1,0,n-1,currChar,i,1);
            str[i] = c;
        }
    }
    //main();
}

/*

4 4
aaaa
2 1 4 a
1 1 b
2 1 2 b
2 1 4 a

*/

