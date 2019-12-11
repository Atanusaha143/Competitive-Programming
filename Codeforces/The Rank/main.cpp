// https://codeforces.com/problemset/problem/1017/A

#include<bits/stdc++.h>
#define C char
#define D double
#define F float
#define LL long long
#define ULLI unsigned long long int
#define LLI long long int
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    LL t,arr[5],brr[5];
    LL pos=1;
    cin>>t;
    cin>>arr[1]>>arr[2]>>arr[3]>>arr[4];
    LL smith = arr[1]+arr[2]+arr[3]+arr[4];
    for(int i=1; i<t; i++)
    {
        LL sum=0;
        cin>>brr[1]>>brr[2]>>brr[3]>>brr[4];
        LL others = brr[1]+brr[2]+brr[3]+brr[4];
        if(others>smith) pos++;
    }
    cout<<pos<<endl;
}
