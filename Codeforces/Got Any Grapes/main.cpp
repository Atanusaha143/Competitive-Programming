#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y,z,a,b,c;
    cin>>x>>y>>z>>a>>b>>c;

    long long a_rem;
    if(a>=x)
    {
        a_rem = a - x;
    }
    else {cout<<"NO"; return 0;}

    long long b_rem;
    if(a_rem+b>=y)
    {
        b_rem = (a_rem+b) - y;
    }
    else {cout<<"NO"; return 0;}

    if(b_rem+c>=z) cout<<"YES";
    else cout<<"NO";
}
