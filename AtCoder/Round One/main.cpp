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
    int a,b;
    cin>>a>>b;
    int arr[3]={1,2,3};
    for(int i=0; i<3; i++)
    {
        if(a==1) arr[0]=0;
        if(a==2) arr[1]=0;
        if(a==3) arr[2]=0;
        if(b==1) arr[0]=0;
        if(b==2) arr[1]=0;
        if(b==3) arr[2]=0;
    }
    for(int i=0; i<3; i++)
    {
        if(arr[i]>0) cout<<arr[i];
    }
}
