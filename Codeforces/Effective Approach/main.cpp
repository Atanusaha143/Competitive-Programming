//https://codeforces.com/contest/227/problem/B

#include<bits/stdc++.h>
#include<iomanip>
#define C char
#define D double
#define F float
#define LL long long
#define ULLI unsigned long long int
#define LLI long long int
#define LLD long long double
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()

{
    LL x,a;
    cin>>x;
    LL xx = x;
    LL xarr[x],yarr[x];
    memset(xarr,0,sizeof(xarr));
    memset(yarr,0,sizeof(yarr));
    for(int i=1; i<=x; i++)
        {
            cin>>a;
            xarr[a]=i;
            yarr[a]=xx;
            xx--;
        }
    LL z,w,m=0,n=0;
    cin>>z;
    while(z--)
    {
        cin>>w;
        m+=xarr[w];
        n+=yarr[w];
    }
    cout<<m<<" "<<n<<endl;
    return 0;
}
