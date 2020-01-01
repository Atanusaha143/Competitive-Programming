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
    int n,i=0,j=0;
    sfi(n);
    S s1,s2;
    cin>>s1>>s2;
    while(1)
    {
        if(i==s1.size() && j==s2.size()) break;
        cout<<s1[i]<<s2[j];
        i++;
        j++;
    }
}
