#include<bits/stdc++.h>
#define ll long long
#define s string
#define d double
using namespace std;
int main()
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  int x;
  cin>>x;
  int a[x],sum=0;
  for(int i=1; i<=x; i++)
  {
      cin>>a[i];
  }

      for(int i=1; i<x; i++)
    {
      for(int j=i+1; j<=x; j++)
      {
          sum = sum + (a[i] * a[j]);
      }
  }
  cout<<sum<<endl;
  return 0;
}
