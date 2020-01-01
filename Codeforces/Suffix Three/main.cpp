// https://codeforces.com/contest/1281/problem/A

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
    LL t;
    sfl(t);
    while(t--)
    {
        S s;
        cin>>s;
        LL x = s.size();
        LL i = x-1;
            if(s[i]=='o' && s[i-1]=='p') {cout<<"FILIPINO"<<NL;}
            else if(s[i]=='u' && s[i-1]=='s' && s[i-2]=='e' && s[i-3]=='d') {cout<<"JAPANESE"<<NL;}
            else if(s[i]=='u' && s[i-1]=='s' && s[i-2]=='a' && s[i-3]=='m') {cout<<"JAPANESE"<<NL;}
            else if(s[i]=='a' && s[i-1]=='d' && s[i-2]=='i' && s[i-3]=='n' && s[i-4]=='m') {cout<<"KOREAN"<<NL;}
    }
    return 0;
}
