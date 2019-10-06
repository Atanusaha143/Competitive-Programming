#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,count;
    cin>>a;
    for(int i=1; i<=a; i++)
    {
        cin>>b;
        count = 0;
        for(int j=1; j<=b; j++)
        {
            if(b%j==0)
            {
                count++;
            }
            
        }
          if(count==2)
          {
            cout<<b<<" eh primo"<<endl;
          }
           else
          {
             cout<<b<<" nao eh primo"<<endl;
          }
    }
    return 0;
}