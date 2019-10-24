#include<bits/stdc++.h>  // A. Pens and Pencils
using namespace std;  // https://codeforces.com/contest/1244/problem/A
int main()
{
    double a,b,c,d,k,t;
    double x,y;
    cin>>t;
    while(t--)
    {
        x = 0,y=0;
        cin>>a>>b>>c>>d>>k;
        x = ceil(a/c);
        y = ceil(b/d);
        if(x+y>k) cout<<"-1"<<'\n';
        else cout<<x<<" "<<y<<'\n';
    }
    return 0;
}
