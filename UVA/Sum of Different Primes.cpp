
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

const int N = 1121;
bool primes[N];
LL dp[188][1121][15], n, k;
const int MOD = 1000000007;
vector <int> allprime;
void isPrime()
{
    mem(primes,true);
    int limit = sqrt(N);
    primes[1] = false;
    primes[2] = true;
    for(int i=4; i<N; i+=2) primes[i] = false;
    for(int i=3; i<=limit; i+=2)
        if(primes[i])
            for(int j=i*i; j<N; j+=i*2)
                primes[j] = false;

    for(int i=2; i<N; i++)
        if(primes[i])
            allprime.PB(i);
}

LL fun(int pos, int sum, int cnt)
{
    if(sum == 0 and cnt == k) return 1;
    if(pos >= 187 or sum < 0 or cnt > k) return 0;
    if(dp[pos][sum][cnt] != -1) return dp[pos][sum][cnt];

    LL total = 0;
    if(allprime[pos] <= sum)
    {
        total += fun(pos+1,(sum-allprime[pos]),cnt+1);
        total += fun(pos+1,sum,cnt);
    }
    else total += fun(pos+1,sum,cnt);
    return dp[pos][sum][cnt] = total;
}

int main()
{
    isPrime();

//    int t; sfi(t); For(tt,1,t) {}
    while(1)
    {
        mem(dp,-1);
        sfi2(n,k);
        if(!n and !k) break;
        LL ans = fun(0,n,0);
        printf("%lld\n", ans);
    }
//    return 0;
}

/*


*/
