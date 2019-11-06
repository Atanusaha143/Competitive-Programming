#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a==0 && b ==1) cout<<"0 1"<<endl;
    else if(a==9 && b ==1) cout<<"9 10"<<endl;
    else if(a<b || a==b)
    {
    ll x = abs(a-b);
    if(x==0)
    {
    cout<<a<<"12"<<" "<<b<<"13"<<endl;
    }
    else if(x==1)
    {
    cout<<a<<"99"<<" "<<b<<"00"<<endl;
    }
    else
    {
    cout<<"-1"<<endl;
    }
    }
    else
    {
        cout<<"-1"<<endl;
    }
return 0;
}
