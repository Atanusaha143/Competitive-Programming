#include<bits/stdc++.h>
#include<iomanip>
#define D double
#define LL long long
#define ULL unsigned long long
#define LLD long long double
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
//#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("in.txt","r",stdin)
#define WRITE  		freopen("out.txt","w",stdout)
using namespace std;
int main()
{
   //IOS;
   S s1 = "donate";
   S s2 = "report";
   LL t;
   cin>>t;
   for(int i=1; i<=t; i++)
   {

       LL z = 0;
       LL n;
       cin>>n;
       cout<<"Case "<<i<<":\n";
       while(n--)
       {
           S s3;
           LL x;
           cin>>s3;
           if(s3==s1)
           {
               cin>>x;
               z+=x;
           }
           else if(s3==s2)
           {
             cout<<z<<endl;
           }
       }
   }
   return 0;
}
