#include<bits/stdc++.h>
#include<iomanip>
#define d double
#define ll long long
#define lld long long double
#define ld long double
#define s string
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

d cum[1000005];

int main()
{
    ios;

    ll t,n,b;
    for(int i=1; i<=1000000; i++)
    {
        cum[i] = cum[i-1] + log(i);
    }
    cin>>t;

    for(int i=1; i<=t; i++)
    {
        cin>>n>>b;
        ll ans = cum[n] / log(b) + 1;
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
