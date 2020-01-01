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
    int a,b,sum=0;
    cin>>a>>b;
    int arr[2*b];
    for(int i=0; i<a; i++)
    {
        for(int i=0; i<2*b; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<2*b; i+=2)
        {
            if(arr[i]+arr[i+1]>0) sum++;
        }
    }
    cout<<sum;
}

