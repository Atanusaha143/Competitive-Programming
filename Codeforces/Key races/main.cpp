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
    int s,a1,t1,a2,t2;
    sfi(s); sfi(a1); sfi(a2); sfi(t1); sfi(t2);
    int first = (s*a1) + (t1+t1);
    int second = (s*a2) + (t2+t2);
    if(first<second) cout<<"First"<<NL;
    else if(first>second) cout<<"Second"<<NL;
    else cout<<"Friendship"<<NL;
}
