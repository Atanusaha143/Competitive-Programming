//https://codeforces.com/contest/550/problem/A

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
    ll a=-1,b=-1;
    s s;
    cin>>s;
    ll l = s.size();

    for(int i=0; i<l-1; i++)
    {
        if(s[i]=='A' && s[i+1]=='B') a=i;
        if(s[i]=='B' && s[i+1]=='A') b=i;
    }

        for(int i=0; i<l; i++)
    {
        if(s[i]=='A' && s[i+1]=='B')
            {
               if(b>=i+2)
               {
                   cout<<"YES\n";
                   return 0;
               }
            }
            if(s[i]=='B' && s[i+1]=='A')
            {
                if(a>=i+2)
                {
                    cout<<"YES\n";
                    return 0;
                }
            }

    }
    cout<<"NO\n";
   return 0;
}
