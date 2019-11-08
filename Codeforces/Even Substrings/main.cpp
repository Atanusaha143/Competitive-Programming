//https://codeforces.com/contest/1139/problem/A

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
    ll x,z=0;
    s s;
    cin>>x;
    cin>>s;
    ll l = s.size();
    for(int i=0; i<l; i++)
    {
        if(s[i]%2==0) z+=i+1;
    }
    cout<<z<<endl;
        return 0;
}
