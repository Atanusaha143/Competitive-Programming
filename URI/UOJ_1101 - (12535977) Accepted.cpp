#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while((cin>>a)&& (cin>>b))
    {
        int sum=0;
        if(a<=0 || b<=0)
        {
            break;
        }
        if(a>b)
        {
            for(int i=b; i<=a; i++)
            {
                sum+=i;
                cout<<i<<" ";
            }
            cout<<"Sum="<<sum<<endl;
        }
        else
        {
            for(int j=a; j<=b; j++)
            {
                sum+=j;
                cout<<j<<" ";
            }
            cout<<"Sum="<<sum<<endl;
        }
    }

    return 0;
}
