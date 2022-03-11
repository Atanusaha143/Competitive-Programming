#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
//typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// *find_by_order = value of an index, order_of_key = index of a value where it should be
//typedef tree<PII, null_type, greater<PII>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }

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
//        LL p1 = (power_mod(base,power/2LL,mod))%mod;
//        p1 = (LL)(p1*p1);
//        return p1%mod;
//    }
//}

//LL original_power(LL base, LL power)
//{
//    if(power==0) return 1LL;
//    else if(power%2LL == 1)
//    {
//        LL p1 = base;
//        LL p2 = (original_power(base,power-1));
//        p1 = (LL)(p1*p2);
//        return p1;
//    }
//    else if(power%2LL == 0)
//    {
//        LL p1 = (original_power(base,power/2LL));
//        p1 = (LL)(p1*p1);
//        return p1;
//    }
//}

//// Grid direction array [4]
//int X[4]= {0,0,-1,1};
//int Y[4]= {1,-1,0,0};
//// Grid direction array [8]
//int X8[8]= {0,0,1,-1,-1,1,1,-1};
//int Y8[8]= {1,-1,0,0,-1,-1,1,1};
//// Knight Direction Array
//int KX[8] = {1,1,2,2,-1,-1,-2,-2};
//int KY[8] = {2,-2,1,-1,2,-2,1,-1};

const int N = 2e6+10;
const LL MOD = 998244353;

int ferry_length;
vector <int> vec;
int dp[301][20000];
int n, cSum[301];

int fun(int pos, int length)
{
    if(pos > n)
    {
        if(length <= ferry_length)
        {
            int remain = cSum[n] - length;
            if(remain <= ferry_length)
            {
                return 1;
            }
        }
        return 0;
    }

    if(dp[pos][length] != -1) return dp[pos][length];
    int val = 0;
    val |= fun(pos+1,length+vec[pos]);
    val |= fun(pos+1,length);
    return dp[pos][length] = val;
}

void print(int pos, int length)
{
    if(pos > n)
    {
        return;
    }

    int val = 0;
    val |= fun(pos+1,length+vec[pos]);
    if(val == dp[pos][length])
    {
        printf("port\n");
        print(pos+1,length+vec[pos]);
        return;
    }
    val |= fun(pos+1,length);
    if(val == dp[pos][length])
    {
        printf("starboard\n");
        print(pos+1,length);
        return;
    }
}

int main()
{

    int t; cin>>t; for(int tt=1; tt<=t; tt++) {

        cin.ignore();
        vec.clear();

        sfi(ferry_length);
        ferry_length *= 100;

        vec.PB(0);
        while(1)
        {
            int x;
            sfi(x);
            if(x == 0) break;
            vec.PB(x);
        }

        for(int i=1; i<min(301,(int)vec.size()); i++) cSum[i] = 0;

        for(int i=1; i<min(301,(int)vec.size()); i++)
        {
            cSum[i] = vec[i] + cSum[i-1];
        }

        int l = 1, r = min(300,(int)vec.size()-1), mid, ans = 0;
        while(l <= r)
        {
            mid = (l + r) / 2;
            n = mid;
            mem(dp,-1);
            int possible = fun(1,0);
            if(possible)
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        n = ans;
        printf("%d\n", ans);
        mem(dp,-1);
        fun(1,0);
        print(1,0);
        if(tt < t) printf("\n");

    }

    //main();
    return 0;
}

/*

1
50
2500
3000
1000
1000
1500
700
800
0

*/

