#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int cnt=0;
         long long arr[10000];
         for(int j=0; j>-1; j++)
         {
             cin>>arr[j];
             cnt++;
             if (cin.get() == '\n') break;
         }
         sort(arr,arr+cnt,greater<long long>());
         cout<<"Case "<<i+1<<": "<<arr[0]<<endl;
    }
    return 0;
}
