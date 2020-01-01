// https://codeforces.com/contest/1278/problem/A

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
    int t;
    cin>>t;
    while(t--)
    {
        LL sum=0;
        S s1,s2;
        cin>>s1>>s2;
        LL x = s1.size();
        LL y = s2.size();
        sort(s1.begin(),s1.end());
            for(int i=0; i<y; i++)
            {
                S dum;
                for(int j=i; j<x+i; j++)
                {
                    dum+=s2[j];
                }
                sort(dum.begin(),dum.end());
                if(s1==dum) {cout<<"YES"<<NL; sum=1; break;}
            }
            if(sum==0) cout<<"NO"<<NL;
    }
    return 0;
}
