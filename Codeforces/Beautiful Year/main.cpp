// https://codeforces.com/contest/271/problem/A

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
    LL n,count=0;
    cin>>n;

    for(int i=n+1; i<100000; i++)
    {
        LL z = i;
    LL arr[5];
    for(int j=4; j>=1; j--)
    {
        LL x = z%10;
        arr[j] = x;
        z = z/10;
    }
    for(int j=1; j<=4; j++)
    {
        if(arr[1] != arr[2] && arr[1] != arr[3] && arr[1] != arr[4] && arr[2] != arr[3] && arr[2] != arr[4] && arr[3] != arr[4]){}
        else
        {
          count++;
        }
    }
    if(count==0)
    {
        for(int i=1; i<=4; i++) {cout<<arr[i];} return 0;
    }
    else
    {
        count=0;
        memset(arr,0,sizeof(arr));
    }
    }
}
