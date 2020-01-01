// https://codeforces.com/problemset/problem/677/A

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
    int t,fheight,sum=0;
    sfi(t); sfi(fheight);
    int arr[t];
    for(int i=0; i<t; i++)
    {
        sfi(arr[i]);
        if(arr[i]>fheight) sum+=2;
        else sum+=1;
    }
    cout<<sum<<NL;
    return 0;
}

