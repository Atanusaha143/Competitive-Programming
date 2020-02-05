#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
#define sz(x) x.size()
#define INF LONG_LONG_MAX
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
}*/
/*LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}*/

int main()
{
    S s;
    cin>>s;
    int siz = sz(s);

        if(siz==1)
            cout<<s;

        else if(siz%2==0)
        {
            S ns = "";
            int x = siz/2;
            int y = x - 1;
            ns = ns + s[y] + s[x];
            while(true)
            {
            if(sz(ns)==siz) break;
            else
            {
                y--;
                ns = ns + s[y];
            }
            if(sz(ns)==siz) break;
            else
            {
                x++;
                ns = ns + s[x];
            }
            }
                cout<<ns;
        }
        else
        {
            S ns = "";
            int x = siz/2;
            int y = x + 1;
            ns = ns + s[x] + s[y];
            while(true)
            {
            if(sz(ns)==siz) break;
            else
            {
                x--;
                ns = ns + s[x];
            }
            if(sz(ns)==siz) break;
            else
            {
                y++;
                ns = ns + s[y];
            }
            }
                cout<<ns;
        }
}
