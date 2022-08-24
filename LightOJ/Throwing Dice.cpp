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

LL original_power(LL base, LL power){
    if(power==0) return 1LL;
    else if(power%2LL == 1){
        LL p1 = base; LL p2 = (original_power(base,power-1));
        p1 = (LL)(p1*p2); return p1;
    }
    else if(power%2LL == 0){
        LL p1 = (original_power(base,power/2LL)); p1 = (LL)(p1*p1);
        return p1;
    }
}

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

const int N = 1e6 + 10;
const int MOD = 1000000007;

int n, x;
LL dp[30][155];

LL fun(int pos, int cur_sum)
{
    if(pos > n)
    {
        if(cur_sum == 0) return 1;
        return 0;
    }
    if(dp[pos][cur_sum] != -1) return dp[pos][cur_sum];
    LL val = 0;
    for(int i=1; i<=6; i++)
    {
        if(cur_sum - i >= 0)
        {
            val += fun(pos+1,cur_sum-i);
        }
    }
    return dp[pos][cur_sum] = val;
}

void solve(int casenum)
{

    cin>>n>>x;
    mem(dp,-1);
    LL maxi = n * 6;
    LL desired_outcome = 0;
    for(int i=x; i<=maxi; i++)
    {
        desired_outcome += fun(1,i);
    }
    LL possible_outcome = original_power(6,n);
    LL g = gcd(desired_outcome,possible_outcome);
    desired_outcome /= g;
    possible_outcome /= g;
    cout<<"Case "<<casenum<<": ";
    if(desired_outcome == 0) cout<<0<<endl;
    else if(possible_outcome == 1) cout<<1<<endl;
    else cout<<desired_outcome<<"/"<<possible_outcome<<endl;
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

Link : https://lightoj.com/problem/throwing-dice

Sol : For a specific sum calculate in how many ways it can be achievable with n dices.
Sum them up and then calculate the answer by the following formula.
Probability = Number of desired outcome / Number of possible outcome

*/
