// https://codeforces.com/contest/1097/problem/A

#include<bits/stdc++.h>
#define C char
#define D double
#define F float
#define LL long long
#define ULLI unsigned long long int
#define LLI long long int
#define LLD long long double
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
#define cnt long long count=0
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    S a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;

        if(a[0]==b[0] || a[0]==b[1] || a[1]==b[0] || a[1]==b[1]) {cout<<"YES\n"; return 0;}
        else if(a[0]==c[0] || a[0]==c[1] || a[1]==c[0] || a[1]==c[1]) {cout<<"YES\n"; return 0;}
        else if(a[0]==d[0] || a[0]==d[1] || a[1]==d[0] || a[1]==d[1]) {cout<<"YES\n"; return 0;}
        else if(a[0]==e[0] || a[0]==e[1] || a[1]==e[0] || a[1]==e[1]) {cout<<"YES\n"; return 0;}
        else if(a[0]==f[0] || a[0]==f[1] || a[1]==f[0] || a[1]==f[1]) {cout<<"YES\n"; return 0;}
        else cout<<"NO\n";
}
