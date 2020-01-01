// https://codeforces.com/problemset/problem/978/B

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
    int n,count=0;
    sfi(n);
    S s;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='x')
        {
            if(s[i-1]=='x' && s[i+1]=='x') count++;
        }
    }
    cout<<count<<NL;
}
