#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
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
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

LL gcd(LL a,LL b) { return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a,LL b) { return (a/gcd(a,b))*b; }

const int n = 1e6;
bool arrPrime[n+1];
vector <int> vecPrime;
void isPrime()
{
    int limit = sqrt(n);
    mem(arrPrime, true);
    arrPrime[0] = arrPrime[1] = false;
    vecPrime.PB(2);
    for(int i=4; i<=n; i+=2) arrPrime[i] = false;
    for(int i=3; i<=n; i+=2)
    {
        if(arrPrime[i])
        {
            vecPrime.PB(i);
            if(i<=limit)
            {
                for(LL j= i*i; j<=n; j+=(2*i))
                    arrPrime[j] = false;
            }
        }
    }
}

int arrFactor[n+1];
void isFactor()
{
    for(int i=0; i<sz(vecPrime); i++)
        for(int j=vecPrime[i]; j<=n; j+=vecPrime[i])
            arrFactor[j]++;
}

int csum[11][n+1];
void calc()
{
    For(i,0,10)
        For(j,1,n)
            if(arrFactor[j]==i) csum[i][j] = csum[i][j-1] + 1;
                else csum[i][j] = csum[i][j-1];
}

int main()
{
    isPrime();
    isFactor();
    calc();

    int t;
    sfi(t);

    while(t--)
    {
        int a,b,n;
        sfi3(a,b,n);

        printf("%d\n", csum[n][b] - csum[n][a-1]);
    }
}

