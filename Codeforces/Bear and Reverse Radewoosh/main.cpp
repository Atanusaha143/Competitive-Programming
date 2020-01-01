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
    int t,p,limak=0,rade=0;
    sfi(t); sfi(p);
    int score[t], penalty[t];
    for(int i=0; i<t; i++) sfi(score[i]);
    for(int i=0; i<t; i++) sfi(penalty[i]);
    int lima_pen=0;
    int rade_pen=0;
    for(int i=0; i<t; i++)
    {
        lima_pen+=penalty[i];
        limak += max(0,score[i]-(p*lima_pen));
    }
    //cout<<limak<<NL;
    for(int i=t-1; i>=0; i--)
    {
        rade_pen+=penalty[i];
        rade += max(0,score[i]-(p*rade_pen));
    }
    //cout<<rade<<NL;
    if(limak>rade) cout<<"Limak"<<NL;
    else if(limak<rade) cout<<"Radewoosh"<<NL;
    else cout<<"Tie"<<NL;
}

