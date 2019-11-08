#include<bits/stdc++.h>
#include<iomanip>
#define d double
#define ll long long
#define lld long long double
#define ld long double
#define s string
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    ios;

    ll a,count=0;
    cin>>a;
    if(a==1) cout<<"1\n";
    else if(a==2) cout<<"1\n";
    else if(a==3) cout<<"1\n";
    else if(a==4) cout<<"1\n";
    else if(a==5) cout<<"1\n";
    else
    {
        ll x = a/5;
        if(a%5!=0) cout<<x+1<<endl;
        else cout<<x<<endl;
    }
    return 0;
}
