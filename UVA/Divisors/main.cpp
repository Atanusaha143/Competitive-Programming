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


                                        /// Solution Starts From Here ///


const int n = 1e5;
bool arrPrime[n+1];
vector <int> vecPrime;

void isPrime()
{
    mem(arrPrime,true);
    arrPrime[0] = false, arrPrime[1] = false, arrPrime[2] = true;
    int limit = sqrt(n);
    vecPrime.PB(2);
    for(int i=4; i<=n; i+=2) arrPrime[i] = false;
    for(int i=3; i<=n; i+=2)
    {
        if(arrPrime[i])
        {
            vecPrime.PB(i);
            if(i<=limit)
            {
                for(LL j=i*i; j<=n; j+=(2*i))
                {
                    arrPrime[j] = false;
                }
            }
        }
    }
}

int arrDiv[100010];
void NOD()
{
    for(int i=1; i<=100000; i++)
    {
        int count = 0;
        int limit = sqrt(i);
        for(int j=1; j<=limit; j++)
        {
            if(j*j==i) count++;
            else if(i%j==0) count+=2;
        }
        arrDiv[i] = count;
    }
}

LL arrSum[100010];
void SOD()
{
    arrSum[0] = 0, arrSum[1] = 1;
    for(int i=2; i<=100000; i++)
    {
        LL sum = 1;
        int tempi = i;
        for(int j=0; j<sz(vecPrime); j++)
        {
            if(vecPrime[j]>tempi) break;
            int power = 0;
            while(tempi%vecPrime[j]==0)
            {
                tempi /= vecPrime[j];
                power++;
            }
            sum *= (pow(vecPrime[j],++power)-1) / (vecPrime[j]-1);
        }
        if(tempi>1) sum = (pow(tempi,2)-1) / (tempi-1);
        arrSum[i] = sum;
    }
}

int main()
{
    isPrime();
    NOD();
    SOD();

    int t;
    sfi(t);

    while(t--)
    {
        int a,b,k;
        sfi3(a,b,k);

        vector <int> divisors;
        for(int i=a; i<=b; i++)
            if(i%k==0)
            divisors.PB(i);
        LL sumNOD = 0, sumSOD = 0;
        for(int i=0; i<sz(divisors); i++)
        {
            sumNOD += arrDiv[divisors[i]];
            sumSOD += arrSum[divisors[i]];
        }
        printf("%lld %lld\n", sumNOD, sumSOD);
    }
}
