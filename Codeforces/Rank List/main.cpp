// https://codeforces.com/contest/166/problem/A

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
    LL n,k,count=0;
    cin>>n>>k;
    LL arr[n];
    LL brr[n];
    LL crr[n];
    memset(arr,0,sizeof(arr));
    memset(brr,0,sizeof(brr));
    memset(crr,0,sizeof(crr));
    for(int i=1; i<=n; i++)
   {
       cin>>arr[i]>>brr[i];
   }
   for(int i=1; i<n; i++)
   {
       for(int j=i+1; j<=n; j++)
       {
           if(arr[i]<arr[j])
           {
               swap(arr[i],arr[j]);
               swap(brr[i],brr[j]);
           }
           if(arr[i]==arr[j])
           {
               if(brr[i]>brr[j])
               {
                   swap(brr[i],brr[j]);
                   swap(arr[i],arr[j]);
               }
           }
       }
   }

    for(int i=1; i<=n; i++)
    {
        if(arr[k]==arr[i] && brr[k]==brr[i]) count++;
    }
    cout<<count<<endl;

    return 0;
}
