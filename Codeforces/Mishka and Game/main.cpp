// https://codeforces.com/problemset/problem/703/A

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
    int t,gf=0,bf=0,m,c;
    sfi(t);
    while(t--)
    {
        cin>>m>>c;
        if(m>c) gf++;
        if(c>m) bf++;
    }
    if(bf>gf) cout<<"Chris"<<NL;
    else if(gf>bf) cout<<"Mishka"<<NL;
    else cout<<"Friendship is magic!^^"<<NL;
    return 0;
}
