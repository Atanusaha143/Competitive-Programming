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

const int MOD = 10000007;
LL bigMOD(int base, int power)
{
    if(power==0) return 1;
    else if(power%2==1)
    {
        LL p1 = base%MOD;
        LL p2 = (bigMOD(base,power-1))%MOD;
        return (p1*p2)%MOD;
    }
    else if(power%2==0)
    {
        LL p1 = (bigMOD(base,power/2))%MOD;
        return (p1*p1)%MOD;
    }
}


int main()
{
//    int t;
//    sfi(t);
//
    while(true)
    {
        int n,k;
        sfi2(n,k);

        if(!n and !k) return 0;

        else
        {
            LL sample1 = (bigMOD(n,k))%MOD;
            LL sample2 = (bigMOD(n,n))%MOD;
            LL sample3 = (2*(bigMOD((n-1),k)))%MOD;
            LL sample4 = (2*(bigMOD((n-1),(n-1))))%MOD;
            printf("%lld\n",(sample1+sample2+sample3+sample4)%MOD);
        }
    }
}

