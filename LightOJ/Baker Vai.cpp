#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define endl              '\n'
#define PI              (2.0*acos(0.0))
#define PB              push_back
#define MP              make_pair
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
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

LL power_mod(LL base, LL power, LL mod){
    if(power==0) return 1LL;
    else if(power%2LL == 1){
        LL p1 = base % mod; LL p2 = (power_mod(base,power-1,mod))%mod;
        p1 = (LL)(p1*p2); return p1%mod;
    }
    else if(power%2LL == 0){
        LL p1 = (power_mod(base,power/2LL,mod))%mod; p1 = (LL)(p1*p1);
        return p1%mod;
    }
}

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

const int N = 100 + 10;
const LL MOD = 1000000007;

int dp[N][N][N], mat[N][N];
int n, m;

int rightdown_x[2] = {0,1};
int rightdown_y[2] = {1,0};

bool validNaki(int x, int y)
{
    return (x <= n and y <= m);
}

int fun(int i, int j, int x)
{
    if(i == n and j == m) return 0;
    if(dp[i][j][x] != -1) return dp[i][j][x];

    int y = (i + j) - x;
    int ans = 0;
    for(int a=0; a<2; a++)
    {
        for(int b=0; b<2; b++)
        {
            int newi = i + rightdown_x[a];
            int newj = j + rightdown_y[a];

            int newx = x + rightdown_x[b];
            int newy = y + rightdown_y[b];

            if(newi == newx and newj == newy)
            {
                if(validNaki(newi,newj) and validNaki(newx,newy))
                {
                    if(newx == n and newj == m and newx == n and newy == m)
                    {
                        ans = max(ans,(fun(newi,newj,newx) + mat[i][j] + mat[x][y]));
                    }
                }
                continue;
            }
            if(validNaki(newi,newj) and validNaki(newx,newy))
            {
                ans = max(ans,(fun(newi,newj,newx) + mat[i][j] + mat[x][y]));
            }
        }
    }
    return dp[i][j][x] = ans;
}

void solve(int casenum)
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>mat[i][j];
        }
    }
    mem(dp,-1);
    int ans = fun(1,2,2) + mat[1][1] + mat[n][m];
    cout<<"Case "<<casenum<<": "<<ans<<endl;
}

int main()
{
    IOS;

//    READ;
//    WRITE;

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/baker-vai

Sol: We will have to visit 2 unique paths exactly. We will move from 1,1 and try to go cell n,m.
It is obvious that going via 2 path from 1,1 to n,m means we can go from 1,1 to n,m via one path and
can back to 1,1 via n,m to 1,1 via another path. So, at the time of traversing we will have to check that we
don't go to the same cell at the same time via the 2 selected cell.

*/

