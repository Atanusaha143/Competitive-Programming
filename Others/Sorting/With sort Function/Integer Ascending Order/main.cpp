#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
