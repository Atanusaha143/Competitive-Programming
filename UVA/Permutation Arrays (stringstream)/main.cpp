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

int arr[5000];
S brr[5000];
int main()
{
   int t;
   S s1,s2;
   sfi(t);
   cin.ignore();
   while(t--)
   {
       cin.ignore();
       int i=1,j=1;
       getline(cin,s1);
       stringstream ss1;
       ss1 << s1;
       while(ss1 >> arr[i]) i++;
        getline(cin,s2);
       stringstream ss2;
       ss2 << s2;
       while(ss2 >> brr[arr[j]]) j++;

       for(int i=1; i<j; i++) cout<<brr[i]<<NL;
       if(t>=1) cout<<NL;
   }
}
