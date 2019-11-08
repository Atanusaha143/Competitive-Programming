https://codeforces.com/contest/43/problem/A

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
    s x[1000];
    ll t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>x[i];
    }
    sort(x,x+t);
    cout<<x[t/2];

   return 0;
}
