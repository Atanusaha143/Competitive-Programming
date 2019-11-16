// https://codeforces.com/contest/363/problem/B

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
    IOS;
    LL n,k,temp=1,sum=0;
    cin>>n>>k;
    LL arr[n];
    memset(arr,0,sizeof(arr));

    for(int i=0; i<n; i++) cin>>arr[i];

    if(n==1 && k==1) cout<<"1\n";

    else
    {
        for(int i=0; i<k; i++) sum+=arr[i];

        LL dum = sum;
        for(int i=k; i<n; i++)
        {
             dum = dum + arr[i] - arr[i-k];
             if(dum<sum)
             {
                 sum = dum;
                 temp = i-(k-2);
             }
        }
        cout<<temp<<endl;
    }

    return 0;
}
