#include<bits/stdc++.h>
using namespace std;
int main()
{
      ios_base::sync_with_stdio (false);
           cin.tie (NULL);
     long long int t;
     cin>>t;
     while(t--)
     {
         long long a;
         cin>>a;
        long long z = a;
         long long arr[a];
         long long brr[a];
         for(long long i=0; i<a; i++)
         {
             cin>>arr[i];
             brr[i] =arr[i];
         }
         sort(arr,arr+a);
         long long x = arr[0];
         long long y= arr[z-1];
         for(long long i=0; i<a; i++)
         {
             if(brr[i]==x)
             {
                 cout<<x<<" "<<y<<endl;
                 break;
             }
             else if(brr[i]==y)
             {
                 cout<<y<<" "<<x<<endl;
                 break;
             }
         }
     }
    return 0;
}
