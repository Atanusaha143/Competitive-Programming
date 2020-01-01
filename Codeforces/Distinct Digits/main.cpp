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
    LL n1,n2,count=0,sum=0,x=0;
    cin>>n1>>n2;
    S s,scp;
    for(int i=n1; i<=n2; i++)
    {
             s = to_string(i);
             scp = to_string(i);
            sort(s.begin(),s.end());
             x = s.size();
            for(int j=0; j<x; j++)
            {
                if(s[j]==s[j+1])
                {
                    count=1;
                    break;
                }
            }
            if(count==0) break;
            else count=0;
    }
    if(count==0)
   {
   	 for(int i=0; i<x; i++)
   	 {
   	 	if (s[i]==s[i+1]) {sum++; break;}
   	 }
   	 if(sum==0) cout<<scp;
   	 else cout<<"-1"<<NL;
}
else cout<<"-1"<<NL;
}
