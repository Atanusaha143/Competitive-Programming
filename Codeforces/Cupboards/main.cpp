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
    LL t,azero=0,bzero=0,aone=0,bone=0;
    cin>>t;
    LL arr[t+1],brr[t+1];
    for(int i=1; i<=t; i++) cin>>arr[i]>>brr[i];
    for(int i=1; i<=t; i++)
    {
        if(arr[i]==0) azero++;
        else aone++;
    }
    for(int i=1; i<=t; i++)
    {
        if(brr[i]==0) bzero++;
        else bone++;
    }
    cout<<min(azero,aone)+min(bzero,bone);
    return 0;
}
