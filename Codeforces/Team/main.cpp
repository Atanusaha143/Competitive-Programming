#include<bits/stdc++.h>
#include<iomanip>
#define D double
#define LL long long
#define ULL unsigned long long
#define LLD long long double
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("in.txt","r",stdin)
#define WRITE  		freopen("out.txt","w",stdout)
using namespace std;
int main()
{
   IOS;

   LL t,count=0;
   cin>>t;
   LL a,b,c;
   while(t--)
   {
       cin>>a>>b>>c;
       LL d = a+b+c;
       if(d>=2) count++;
   }
   cout<<count<<endl;
    return 0;
}
