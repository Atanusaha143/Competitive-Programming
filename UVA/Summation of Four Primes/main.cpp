#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string

#define sz(x) x.size()
#define INF LONG_MAX
#define IINF LLONG_MAX
#define PI (2.0*acos(0.0))

#define sfi(x) scanf("%d",&x)
#define sfi2(x,y) scanf("%d %d",&x,&y)
#define sfi3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sfl(x) scanf("%lld",&x)
#define sfl2(x,y) scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x) scanf("%lf",&x);
#define sfd2(x,y) scanf("%lf %lf",&x,&y);

#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(a,min3(b,c,d))

#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define For(i, j, k) for(int i = j; i <= k; i++)
#define Rof(i, j, k) for(int i = j; i >= k; i--)
#define all(x) x.begin(),x.end()
#define asort(x) sort(all(x));
#define dsort(x) sort(all(x), greater<int>())
#define unq(x) x.erase(unique(x.begin(),x.end()),x.end())

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;

LL gcd(LL a,LL b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}

LL bigmod(LL base, LL power, LL mod)
{
    if(power==0) return 1;
    else if(power%2==1)
    {
        LL value1 = base % mod; LL value2 = (bigmod(base,power-1,mod))%mod;
        return (value1*value2)%mod;
    }
    else
    {
        LL value1 = (bigmod(base,power/2,mod))%mod;
        return (value1*value1)%mod;
    }
}


//  (2^(p-1))*((2^p)−1)) is a perfect number whenever ((2^p)−1) is prime, where p is an integer.
//   The theorem was proved by Euclid.

bool checkPrime(int n)
{
    int limit = sqrt(n);
    For(i,2,limit)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

const int n = 1e7;
bool arrPrime[n+10];
vector <int> allPrime;
void isPrime()
{
    mem(arrPrime,true);
    arrPrime[0]= false,arrPrime[1] = false, arrPrime[2]= true;
    allPrime.PB(2);
    int limit = sqrt(n);
    for(int i=4; i<=n; i+=2) arrPrime[i] = false;
    for(int i=3; i<=n; i+=2)
    {
        if(arrPrime[i])
        {
            allPrime.PB(i);

            if(i<=limit)
            {
                for(int j=i*i; j<=n; j+=(2*i))
                    arrPrime[j] = false;
            }
        }
    }
}
int main()
{
    isPrime();

    int n;
    while(sfi(n)!= EOF)
    {
        bool chk = false;
        if(n%2)
        {
            int rem = n-5;
            for(int i=2; i<=n; i++)
            {
                int diff = rem - i;
                if(arrPrime[i] and arrPrime[diff])
                {
                    printf("2 3 %d %d\n", i, diff);
                    chk = true;
                    break;
                }
            }
        }
        else
        {
            int rem = n-4;
            for(int i=2; i<=n; i++)
            {
                int diff = rem - i;
                if(arrPrime[i] and arrPrime[diff])
                {
                    printf("2 2 %d %d\n", i, diff);
                    chk = true;
                    break;
                }
            }
        }

        if(!chk) printf("Impossible.\n");
    }
}
