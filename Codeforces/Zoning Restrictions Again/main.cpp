#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
#define PI (2.0*acos(0.0))
#define sfi(x) scanf("%d",&x)
#define sfl(x) scanf("%I64d",&x)
#define sfd(x) scanf("%lf",&x)
#define sfs(x) scanf("%s",x)
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
    int n,h,m,profit=0;
    sfi(n); sfi(h); sfi(m);
    int arr[n+1];
    for(int i=1; i<=n; i++) arr[i]=h;
    for(int j=1; j<=m; j++)
    {
        int l,r,x;
        sfi(l); sfi(r); sfi(x);
        for(int k=l; k<=r; k++)
        {
            arr[k]=min(arr[k],x);
        }
    }
    for(int i=1; i<=n; i++) profit+=arr[i]*arr[i];
    cout<<profit<<NL;
}
