/// Time - 0.13s
/// Memory - 51M

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
int zero[n+1], one[n+1], two[n+1], three[n+1], four[n+1], five[n+1], six[n+1], seven[n+1], eight[n+1], nine[n+1], ten[n+1];
void isFactor()
{
    for(int i=0; i<sz(vecPrime); i++)
        for(int j=vecPrime[i]; j<=n; j+=vecPrime[i])
            arrFactor[j]++;
}

void calc()
{
    int count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==0)
        {
            zero[i] = ++count;
        }
        else zero[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==1)
        {
            one[i] = ++count;
        }
        else one[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==2)
        {
            two[i] = ++count;
        }
        else two[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==3)
        {
            three[i] = ++count;
        }
        else three[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==4)
        {
            four[i] = ++count;
        }
        else four[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==5)
        {
            five[i] = ++count;
        }
        else five[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==6)
        {
            six[i] = ++count;
        }
        else six[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==6)
        {
            six[i] = ++count;
        }
        else six[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==7)
        {
            seven[i] = ++count;
        }
        else seven[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==8)
        {
            eight[i] = ++count;
        }
        else eight[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==9)
        {
            nine[i] = ++count;
        }
        else nine[i] = count;
    }
    count = 0;
    for(int i=1; i<=n; i++)
    {
        if(arrFactor[i]==10)
        {
            ten[i] = ++count;
        }
        else ten[i] = count;
    }
}

int main()
{
    IOS;

    isPrime();
    isFactor();
    calc();

    int t;
    sfi(t);

    while(t--)
    {
        int a,b,n;
        sfi3(a,b,n);

        if(n==0)
        {
            cout<<zero[b]-zero[a-1]<<NL;
        }
        else if(n==1)
        {
            cout<<one[b]-one[a-1]<<NL;
        }
        else if(n==2)
        {
            cout<<two[b]-two[a-1]<<NL;
        }
        else if(n==3)
        {
            cout<<three[b]-three[a-1]<<NL;
        }
        else if(n==4)
        {
            cout<<four[b]-four[a-1]<<NL;
        }
        else if(n==5)
        {
            cout<<five[b]-five[a-1]<<NL;
        }
        else if(n==6)
        {
            cout<<six[b]-six[a-1]<<NL;
        }
        else if(n==7)
        {
            cout<<seven[b]-seven[a-1]<<NL;
        }
        else if(n==8)
        {
            cout<<eight[b]-eight[a-1]<<NL;
        }
        else if(n==9)
        {
            cout<<nine[b]-nine[a-1]<<NL;
        }
        else if(n==10)
        {
            cout<<ten[b]-ten[a-1]<<NL;
        }
    }
}

