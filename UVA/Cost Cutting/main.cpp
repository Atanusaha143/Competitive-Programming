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

   LL t,count=0;
   cin>>t;
   LL arr[3];
   for(int i=1; i<=t; i++)
   {
       for(int i=0; i<3; i++)
       {
           cin>>arr[i];
       }
       sort(arr,arr+3);
       cout<<"Case "<<i<<": "<<arr[1]<<endl;
   }
    return 0;
}
