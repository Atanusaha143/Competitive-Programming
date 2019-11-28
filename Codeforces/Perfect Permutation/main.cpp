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
    LL n,arr[105];
    cin>>n;
    if(n%2==1)
    {
        cout<<"-1\n";
        return 0;
    }
    for(int i=1; i<=100; i++)
    {
        arr[i] = i;
    }
    for(int i=1; i<=n; i+=2)
    {
        swap(arr[i],arr[i+1]);
    }
    for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
    return 0;
}
