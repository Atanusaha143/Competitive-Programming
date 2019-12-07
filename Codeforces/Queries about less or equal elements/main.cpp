#include<bits/stdc++.h>
using namespace std;
long long arr[1000001];
long long brr[1000001];
int main()
{
    long long a,b;
    cin>>a>>b;
    for(int i=1; i<=a; i++) cin>>arr[i];
    for(int i=1; i<=b; i++) cin>>brr[i];
    sort(arr+1,arr+a+1);
    for(int i=1; i<=b; i++)
    {
        long long l=1, r = a, indx = 0;
        while(l<=r)
        {
            long long mid = (l+r)/2;
        if(arr[mid]>brr[i]) r = mid-1;
        else if(arr[mid]<=brr[i]) {indx = mid; l=mid+1;}
        }
        cout<<indx<<" ";
    }
}
