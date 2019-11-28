#include<bits/stdc++.h>
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
    LL n, maxcounter=1, mincounter=1;
    cin>>n;
    LL arr[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(arr[mincounter]>=arr[i])
        {
            mincounter = i;
        }
        else if(arr[maxcounter]<arr[i])
        {
            maxcounter = i;
        }
    }

         if(mincounter==n && maxcounter==1) cout<<"0\n";
        else if(mincounter>maxcounter) cout<<(n-mincounter)+(maxcounter-1);
        else cout<<(n-mincounter)+(maxcounter-1)-1;
    return 0;
}
