#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,a,sum;
    cin>>x;
    for(int i=1; i<=x; i++)
    {
        cin>>a;
        sum = 0;
        for(int i=1; i<a; i++)
        {
            if(a%i==0)
            {
                sum+=i;
            }
        }
        if(sum==a)
            cout<<a<<" eh perfeito"<<endl;
        else
            cout<<a<<" nao eh perfeito"<<endl;
    }
    return 0;
}
