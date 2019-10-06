#include<bits/stdc++.h>
using namespace std;
int main()
{
   int x,sum;
   while(1)
   {
       cin>>x;
       sum=0;
       if(x==0)
       {
           break;
       }
       else
       {
           if(x%2==0)
           {
              sum=sum+x;
           }
           else
           {
               x=x+1;
               sum=sum+x;
           }
       }
         for(int i=0; i<4; i++)
           {
               x=x+2;
               sum=sum+x;
           }
           cout<<sum<<endl;
   }
   return 0;
}
