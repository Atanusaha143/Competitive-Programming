#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        ll a[x],b[x];
        for(int i=0;i<x;i++)
        {
            cin>>a[i];
        }
        sort(a,a+x,greater<int>());
        ll i,j,z=x,rest;
        while(true)
        {
        ll count=0;

        for(i=0;i<x;i++)
        {
            if(a[i]>=z)
            {
                count++;
            }
            if(count==z)
                {
                    rest=z;
                    break;
                }
        }
        if(count==z)
            break;
        z--;
        }
        cout<<rest<<endl;
    }
    return 0;
}
