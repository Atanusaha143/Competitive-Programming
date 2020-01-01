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

LL arr[100001];
int main()
{
    LL t,count=1;
    sfl(t);
    for(int i=0; i<t; i++) sfl(arr[i]);
    for(int i=1; i<t; i++)
    {
        if(arr[i-1]!=arr[i]) count++;
    }
    cout<<count<<NL;
}
