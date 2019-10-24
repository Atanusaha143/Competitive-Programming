#include<bits/stdc++.h>
using namespace std;
int main()
{
              ios_base::sync_with_stdio (false);
  cin.tie (NULL);
    long long t=0,v=0,sum=0,dum=0,z=0;
    cin>>t;
    long long arr[t];
    double b=t;
    double x = b/2;
       long long a = ceil(x);
   for(int i=0; i<t; i++)
   {
       cin>>arr[i];
   }
   sort(arr,arr+t,greater<int>());

   for(int i=0; i<a; i++) sum+=arr[i];
   for(int j=a; j<t; j++) dum+=arr[j];
   t = ceil(pow(sum,2));
   v = pow(dum,2);
   z = t + v;
   cout<<z<<endl;
    return 0;
}

