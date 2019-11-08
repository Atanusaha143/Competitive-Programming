//https://codeforces.com/contest/1256/problem/A

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    ll t,a,b,n,s,x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n>>s;
        x = s%n;
        z = a * n + b;
        if(x<=b && z>=s) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
