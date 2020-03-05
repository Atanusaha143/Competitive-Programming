#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long arr[n];

        long long mini = 1000000;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];

            if(mini>arr[i]) mini = arr[i];
        }

        cout<<mini<<endl;
    }
}
