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

//LL power_mod(LL base, LL power, LL mod)
//{
//    if(power==0) return 1LL;
//    else if(power%2LL == 1)
//    {
//        LL p1 = base % mod;
//        LL p2 = (power_mod(base,power-1,mod))%mod;
//        p1 = (LL)(p1*p2);
//        return p1%mod;
//    }
//    else if(power%2LL == 0)
//    {
//        LL p1 = (power_mod(base,power/2,mod))%mod;
//        p1 = (LL)(p1*p1);
//        return p1%mod;
//    }
//}

// Grid direction array [4]
int X[4]= {0,0,-1,1};
int Y[4]= {1,-1,0,0};
// Grid direction array [8]
int X8[8]= {0,0,1,-1,-1,1,1,-1};
int Y8[8]= {1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }

const int N = 2e5+10;
const LL MOD = 1000000007;
int n, pig_weight, total_weight;
int dp[505][10005];
vector <PII> vec;

int fun(int pos, int w)
{
    if(pos >= vec.size())
    {
        if(w == 0) return 0;
        return 1e9;
    }
    if(dp[pos][w] != -1) return dp[pos][w];
    int val = 1e9;
    if(vec[pos].second <= w)
    {
        for(int i=1; i*vec[pos].second<=w; i++)
        {
            val = min(val, fun(pos+1,w-(i*vec[pos].second))+(i*vec[pos].first));
        }
    }
    val = min(val, fun(pos+1,w));
    return dp[pos][w] = val;
}

int main()
{
    int t; sfi(t); For(tt,1,t) {

        sfi2(pig_weight,total_weight);
        sfi(n);

        map <int,int> visited;
        for(int i=1; i<=n; i++)
        {
            int u, v;
            sfi2(u,v);
            if(visited.find(v) == visited.end())
            {
                visited[v] = u;
            }
            else
            {
                if(u < visited[v])
                {
                    visited[v] = u;
                }
            }
        }

        for(PII x : visited)
        {
            int w = x.first;
            int v = x.second;
            vec.PB({v,w});
        }

        int remain_weight = total_weight - pig_weight;
        mem(dp,-1);
        int ans = fun(0,remain_weight);
        if(ans == 1e9) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", ans);

        vec.clear();
    }

    return 0;
}

/*

https://www.spoj.com/problems/PIGBANK/

*/
