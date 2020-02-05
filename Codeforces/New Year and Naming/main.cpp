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
#define mem(arr,val) memset(arr,val,sizeof(arr))
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
    LL n,m;
    cin>>n>>m;
    S s1[n+1],s2[m+1];
    for(int i=1; i<=n; i++) cin>>s1[i];
    for(int i=1; i<=m; i++) cin>>s2[i];
    LL t;
    cin>>t;
    while(t--)
    {
        LL x;
        sfl(x);
        if(x<=n && x<=m)
        {
            S s = s1[x]+s2[x];
            cout<<s<<NL;
        }
        else if(x>n && x>m)
        {
            LL m1,n1;
            D nn = ceil((x%n)/1.00);
            D mm = ceil((x%m)/1.00);
            n1 = nn;
            m1 = mm;
            if(nn==0) n1 = n;
            if(mm==0) m1 = m;
            S s = s1[n1]+s2[m1];
            cout<<s<<NL;
        }
        else if(x<=n && x>m)
        {
            LL m1;
            D mm = ceil((x%m)/1.00);
            m1 = mm;
            if(mm==0) m1=m;
            S s = s1[x]+s2[m1];
            cout<<s<<NL;
        }
        else
        {
            LL n1;
            D nn = ceil((x%n)/1.00);
            n1 = nn;
            if(nn==0) n1=n;
            S s = s1[n1]+s2[x];
            cout<<s<<NL;
        }
    }
}
