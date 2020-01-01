#include<iostream>
#include<string>
#include<algorithm>
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
    LL n;
    sfl(n);
    int one=0,zero=0,sum=0,dum=0,oone=0,zzero=0;
    S s;
    cin>>s;
    LL x = s.size();
    if(x==1) { cout<<"1"<<NL; cout<<s<<NL;}
    else
    {
       for(int i=0; i<x; i++)
       {
       	if(s[i]=='0') zero++;
       	else one++;
       }
       if(zero==one)
       {
       	cout<<"2"<<NL;
       	cout<<s[0];
       	cout<<" ";
       	for(int i=1; i<x; i++) cout<<s[i];
       }
       else
       {
       	cout<<"1"<<NL;
       	cout<<s;
       }
    }
}
