// https://codeforces.com/contest/734/problem/A

#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
#define PI (2.0*acos(0.0))
#define sfi(x) scanf("%d",&x)
#define sfl(x) scanf("%I64d",&x)
#define sfd(x) scanf("%lf",&x)
#define sfs(x) scanf("%s",x)
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

int main()
{
    LL t,a=0,d=0;
    sfl(t);
    S s;
    cin>>s;
    for(int i=0; i<t; i++)
    {
        if(s[i]=='A') a++;
        else if(s[i]=='D') d++;
    }
    if(a>d) cout<<"Anton"<<NL;
    else if(d>a)cout<<"Danik"<<NL;
    else cout<<"Friendship"<<NL;
    return 0;
}
