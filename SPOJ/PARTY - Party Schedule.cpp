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

const int N = 105+10;
const int MOD = 1000000007;
int dp[105][505];
int w, n, limit;

struct srr{
    int m, f;
};
srr arr[N];

int fun(int pos, int sum)
{
    if(sum > w) return NINF;
    if(pos == n) return 0;
    if(dp[pos][sum] != -1) return dp[pos][sum];
    int val1 = fun(pos+1,sum+arr[pos].m)+arr[pos].f;
    int val2 = fun(pos+1,sum);
    return dp[pos][sum] = max(val1,val2);
}

int fun1(int pos, int sum)
{
    if(sum == limit) return 0;
    if(pos >= n) return 1e7;
    if(dp[pos][sum] != -1) return dp[pos][sum];
    int val = 1e7;
    int curr = min(limit,(sum+arr[pos].f));
    val = min(val,fun1(pos+1,curr)+arr[pos].m);
    val = min(val,fun1(pos+1,sum));
    return dp[pos][sum] = val;
}

int main()
{
//    int t; sfi(t); For(tt,1,t) {}

    while(1)
    {
        sfi2(w,n);
        if(!w and !n) break;
        for(int i=0; i<n; i++)
        {
            sfi(arr[i].m);
            sfi(arr[i].f);
        }

        mem(dp,-1);
        int ans1 = fun(0,0);
        limit = ans1;
        mem(dp,-1);
        int ans2 = fun1(0,0);
        printf("%d %d\n", ans2, ans1);
    }
    return 0;
}

/*

50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0

*/

