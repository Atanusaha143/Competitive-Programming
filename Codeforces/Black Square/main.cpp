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
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;


int main()
{
    LL a,b,c,d,sum=0;
    sfl(a); sfl(b); sfl(c); sfl(d);
    S s;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='1') sum+=a;
        else if(s[i]=='2') sum+=b;
        else if(s[i]=='3') sum+=c;
        else if(s[i]=='4') sum+=d;
    }
    cout<<sum<<NL;
}
