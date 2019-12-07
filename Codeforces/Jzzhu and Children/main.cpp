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
    LL t;
    D n,maxi=0,dmaxi=0,emaxi=0,umaxi=0;
    cin>>t>>n;
    LL arr[t+1];
    LL brr[t+1];
    for(int i=1; i<=t; i++)
    {
        cin>>arr[i];
        brr[i] = ceil(arr[i]/n);
    }
    for(int i=1; i<=t; i++)
    {
        if(maxi<=brr[i])
        {
            maxi = brr[i];
            umaxi = i;
        }
    }
    cout<<umaxi<<endl;
}
