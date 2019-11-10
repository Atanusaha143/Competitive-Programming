#include<bits/stdc++.h>
#include<iomanip>
#define d double
#define ll long long
#define lld long long double
#define ld long double
#define s string
#define pi 3.14159265
//#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
  //  ios;

    ll n;
    cin>>n;
    for(ll j=1; j<=n; j++)
    {
        ll a,count=0;
        cin>>a;

      while(true)
    {
        if(a%2==1) count++;
        a = a/2;
        if(a==0) break;
    }

    if(count%2==0)
    {
        cout<<"Case "<<j<<": even\n";
    }
    else
    {
        cout<<"Case "<<j<<": odd\n";
    }
    }
    return 0;
}
