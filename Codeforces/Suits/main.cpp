// https://codeforces.com/contest/1271/problem/A

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
        LL a,b,c,d,e,f,ans=0,dans=0;
        sfl(a); sfl(b); sfl(c); sfl(d); sfl(e); sfl(f);
        LL min_1 = min(a,d);
        LL min_2 = min(d,min(b,c));
        LL maxi = max(e,f);
            if(maxi==e)
            {
                ans = e * min_1;
                if(min_1==d) cout<<ans<<NL;
                else
                {
                 LL d2 = d-min_1;
                 dans = f * min(d2,min(b,c));
                 cout<<ans+dans<<NL;
                }
            }
            else
            {
                ans = f * min_2;
                if(min_2==d) cout<<ans<<NL;
                else
                {
                    LL d2 = d-min_2;
                    dans = e * min(a,d2);
                    cout<<ans+dans<<NL;
                }
            }
    return 0;
}
