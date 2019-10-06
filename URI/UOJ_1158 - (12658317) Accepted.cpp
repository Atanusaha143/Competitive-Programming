#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,sum;
    cin>>x;
    for(int i=1; i<=x; i++)
    {
        int a,b;
        cin>>a>>b;
        sum=0;
          if(a%2!=0)
          {
              sum=sum+a;
          }
          else
          {
               a=a+1;
              sum=sum+a;
          }
          for(int i=0; i<b-1; i++)
          {
              a=a+2;
              sum=sum+a;
          }
     cout<<sum<<endl;
    }
    return 0;
}
