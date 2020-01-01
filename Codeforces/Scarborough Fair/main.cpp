// https://codeforces.com/problemset/problem/897/A

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
    int n,m;
    sfi(n); sfi(m);
    /*char c[n+1];
    for(int i=1; i<=n; i++) cin>>c[i];*/ //This will also work
    S s;
    cin>>s;
    while(m--)
    {
        int l,r;
    sfi(l); sfi(r);
    char c1,c2;
    cin>>c1>>c2;
        for(int j=l-1; j<r; j++)
        {
            if(s[j]==c1) s[j]=c2;
        }
    }
    //for(int i=1; i<=n; i++) cout<<c[i];
    cout<<s<<NL;
}
