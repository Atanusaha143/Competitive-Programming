#include<bits/stdc++.h>
#define ll long long
#define s string
#define d double
using namespace std;
int main()
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  int a, b;
  cin>>a>>b;
  if(a>b)
  {
      int c = 2*b;
      int e = a-c;
      if(e<0) cout<<"0"<<endl;
      else cout<<e<<endl;
  }
  else cout<<"0"<<endl;



  return 0;
}
