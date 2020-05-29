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

bool arrPrime[61234],arrSeg[123456];
const int n = 50000;
vector <int> vecPrimes;

void nPrime()
{
    mem(arrPrime,true);
    vecPrimes.PB(2);
    for(int i=4; i<=n; i+=2) arrPrime[i] = false;
    for(int i=3; i<=n; i+=2)
    {
        if(arrPrime[i])
        {
            vecPrimes.PB(i);

            if(i<=sqrt(n))
            {
                for(int j=i*i; j<=n; j+=(2*i))
                    arrPrime[j] = false;
            }
        }
    }
}

int segPrime(LL l, LL r)
{
    mem(arrSeg,true);
    if(l==1) arrSeg[0] = false;
    for(int i=0; (LL)vecPrimes[i]*vecPrimes[i]<=r; i++)
    {
        int currPrime = vecPrimes[i];
        LL base = (l/currPrime)*currPrime;
        if(base<l) base += currPrime;
        for(LL j=base; j<=r; j+=currPrime)
            arrSeg[j-l] = false;
        if(base==currPrime) arrSeg[base-l] = true;
    }

    int count=0;
    for(int i = 0; i<(r-l+1); i++)
    {
        if(arrSeg[i])
            count++;
    }
    return count;
}

int main()
{
    nPrime();

    int t;
    sfi(t);

    for(int tt=1; tt<=t; tt++)
    {
        LL l,r;
        sfl2(l,r);
        printf("Case %d: %d\n",tt,segPrime(l,r));

    }
}
