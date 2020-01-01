// https://codeforces.com/contest/721/problem/A

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
    int t,sum=0;
    int arr[101],j=0;
    cin>>t;
    S s;
    cin>>s;
    for(int i=0; i<=t; i++)
    {
        if(s[i]=='B') sum++;
        else if(sum>0)
        {
            arr[j]=sum;
            j++;
             sum=0;
        }
    }
    if(j==0) cout<<"0"<<NL;
    else
    {
        cout<<j<<endl;
        for(int i=0; i<j; i++) cout<<arr[i]<<" ";
    }
    return 0;
}
