// https://codeforces.com/problemset/problem/711/A

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
    int t,flag=0;
    sfi(t);
    C a[1000],b[1000],c[1000],d[1000],e[1000];

    for(int i=0; i<t; i++) cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];

    for(int i=0; i<t; i++)
    {
        if(a[i]=='O' && b[i]=='O')
        {
            a[i]='+';
            b[i]='+';
            flag=1;
            break;
        }
        else if(d[i]=='O' && e[i]=='O')
        {
            d[i]='+';
            e[i]='+';
            flag=1;
            break;
        }
    }
    if(flag==0) cout<<"NO"<<NL;
    else
    {
        cout<<"YES"<<NL;
        for(int i=0; i<t; i++)
        {
            cout<<a[i]<<b[i]<<c[i]<<d[i]<<e[i]<<NL;
        }
    }
    return 0;
}
