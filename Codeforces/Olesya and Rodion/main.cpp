#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    ll n,t;
    cin>>n>>t;
    if(n==1 && t==10) cout<<"-1";
    else if(n==2 && t==10) cout<<"10";
        else if(n>2 && t==10)
    {
        cout<<"1";
        for(int i=2; i<=n; i++) cout<<"0";
    }

    else
    {
        for(int i=1; i<=n; i++)
        {
            cout<<t;
        }
    }
    return 0;
}
