// https://codeforces.com/contest/1277/problem/A

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
        S s1 = s;
        LL x = s.size();
        for(int i=0; i<x; i++) s1[i]='1';
        int a = stoi(s);
        int b = stoi(s1);
        cout<<9*(x-1)+(a/b)<<NL;
    }
    return 0;
}
