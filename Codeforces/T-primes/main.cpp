#include<bits/stdc++.h>
#include<iomanip>
#define D double
#define LL long long
#define LLD long long double
#define LD long double
#define S string
#define PI 3.14159265
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
   IOS;

   LL t;
   cin>>t;
   for(int i=1; i<=t; i++)
   {
       LL n,count;
       cin>>n;
       if(n==1) cout<<"NO\n";
       else
       {
           LL z;
           LL m = sqrt(n);
           count=0;
           if(m*m==n)
           {
               z = sqrt(m);
               for(int i=1; i<=z; i++)
               {
                   if(m%i==0)
                   {
                       count++;
                   }
                   if(count>1) break;
               }
           }
            if(count==1) cout<<"YES\n";
           else cout<<"NO\n";
       }

   }
    return 0;
}
