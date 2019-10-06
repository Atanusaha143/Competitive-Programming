#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll x,y,sum=0;
    cin>>x>>y;
    
    if(x>y)
        swap(x,y);
        
    for(ll i=x; i<=y; i++)
    {
        if(i%13!=0)
        {
            sum+=i;
        }
    }
        cout<<sum<<endl;

    return 0;
}
