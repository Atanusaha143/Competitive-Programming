#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
#define PI (2.0*acos(0.0))
#define sfi(x) scanf("%d",&x)
#define sfi2(x,y) scanf("%d %d",&x,&y)
#define sfi3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sfl(x) scanf("%lld",&x)
#define sfl2(x,y) scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x) scanf("%lf",&x);
#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define mem(ara,val) memset(ara,val,sizeof(ara))
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

/*LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}*/

int main()
{
    LL t;
    sfl(t);
    while(t--)
    {
        LL n,a,b,cost=0;
        sfl3(n,a,b);

        LL half_b = b/2; // now 'a' = 'half_b' = 1 Liter
        LL mini = min(a,half_b);

        if(mini==a) cout<<n*a<<NL; // When minimum cost is 'a'
        else                       // When minimum cost is 'half_b'
        {
            cost = (n/2)*b; // As we can't take half of 'b' then we have to use full of 'b'
            if(n%2!=0) cost+=a; // When 'n' is odd then For the remaining 1 Liter we need 'a'
            cout<<cost<<NL;
        }
    }
}
