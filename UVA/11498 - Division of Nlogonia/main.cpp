#include<bits/stdc++.h>
#include<iomanip>
#define C char
#define D double
#define LL long long
#define ULL unsigned long long
#define LLI long long int
#define LLD long long double
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    IOS;
   while(true)
   {
       LL t;
       cin>>t;
       LL n,m,x,y;
       if(t==0) break;
       else
       {
           cin>>n>>m;
       for(int i=1; i<=t; i++)
       {
           cin>>x>>y;
           if(n==x || n==y || m==x || m==y)
            cout<<"divisa\n";
           else
           {
               if(x>n && y>m) cout<<"NE\n";
               else if(x<n && y>m) cout<<"NO\n";
               else if(x<n && y<m) cout<<"SO\n";
               else if(x>n && y<m) cout<<"SE\n";
           }
       }
       }
   }

   return 0;
}
