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


int main()
{
    int t;
    sfi(t);

    while(t--)
    {
        LL a,b;
        sfl2(a,b);
        if(a==b) printf("0\n");
        else
        {
            if(a>b)
            {
                LL count = 0;
                while(a%8==0)
                {
                    if(a==b) break;
                    if(a/8>=b) a/=8;
                    else break;
                    count++;
                }
                if(a==b)
                {
                  printf("%lld\n",count);
                  continue;
                }
                while(a%4==0)
                {
                    if(a==b) break;
                    if(a/4>=b) a/=4;
                    else break;
                    count++;
                }
                if(a==b)
                {
                  printf("%lld\n",count);
                  continue;
                }
                while(a%2==0)
                {
                    if(a==b) break;
                    if(a/2>=b) a/=2;
                    else break;
                    count++;
                }
                if(a==b)
                {
                    printf("%lld\n",count);
                }
                else printf("-1\n");
            }
            else if(a<b)
            {
                LL count = 0;
                LL keep = b;
                while(b%8==0)
                {
                    if(a==b) break;
                    if(b/8>=a) b/=8;
                    else break;
                    count++;
                }
                if(a==b)
                {
                  printf("%lld\n",count);
                  continue;
                }
                while(b%4==0)
                {
                    if(a==b) break;
                    if(b/4>=a) b/=4;
                    else break;
                    count++;
                }
                if(a==b)
                {
                  printf("%lld\n",count);
                  continue;
                }
                while(b%2==0)
                {
                    if(a==b) break;
                    if(b/2>=a) b/=2;
                    else break;
                    count++;
                }
                if(a==b)
                {
                    printf("%lld\n",count);
                }
                else printf("-1\n");
            }

        }
    }
}
 
