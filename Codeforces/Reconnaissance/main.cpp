#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,d,sum=0;
    cin>>n>>d;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(abs(arr[i]-arr[j])<=d) sum+=2;
        }
    }
    cout<<sum<<endl;
    return 0;
}
