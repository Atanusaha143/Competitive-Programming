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
    IOS;
   int t;
   S s;
     cin>>t;
     while(t--)
     {
        int n;
        D sum=0;
        cin>>n;
        char arr[n];
        D brr[n];
        for(int i=0; i<n; i++) cin>>arr[i]>>brr[i];
        int x;
        cin>>x;
        cin.ignore();
        for(int k=0; k<x; k++)
        {
        getline(cin,s);
        for(int i=0; i<s.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i]==arr[j]) sum+=brr[j];
            }
        }
        }
        cout<<fixed<<setprecision(2)<<sum/100.00<<"$"<<NL;
     }
     return 0;
}
