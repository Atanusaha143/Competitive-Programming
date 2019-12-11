// https://codeforces.com/contest/149/problem/A

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
    int k,count=0;
    cin>>k;
    int arr[12];
    for(int i=0; i<12; i++) cin>>arr[i];
    int mount=0;
    sort(arr,arr+12,greater<int>());
    for(int i=0; i<12; i++)
    {
        mount+=arr[i];
        count++;
        if(mount>=k) break;
    }
    if(k==0) cout<<"0\n";
    else if(mount<k) cout<<"-1\n";
    else cout<<count<<endl;
}
