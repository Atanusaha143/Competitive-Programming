#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,sum=0;
    while(cin>>a)
    {
        cin>>b;
        while(b<=0)
        {
            cin>>b;
        }
        sum+=a;
        for(int i=0; i<b-1;i++)
        {
            a+=1;
            sum+=a;
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
