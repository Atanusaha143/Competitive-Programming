#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a[3],b[3];
  int t,x,y,count;
  cin>>t;
  while(t--)
  {
    for(int i=0; i<3; i++)
    {
      cin>>a[i];
    }
    for(int i=0; i<3; i++)
    {
      cin>>b[i];
    }
    if(a[0]>a[1] && b[0]>b[1])
    {
      count++;
    }
    else if(a[0]<a[1] && b[0]<b[1])
    {
      count++;
    }
    else if(a[0]==a[1] && b[0]==b[1])
    {
      count++;
    }
    else{}

    if(a[1]>a[2] && b[1]>b[2])
    {
      count++;
    }
    else if(a[1]<a[2] && b[1]<b[2])
    {
      count++;
    }
    else if(a[1]==a[2] && b[1]==b[2])
    {
      count++;
    }
   else{}

    if(a[0]>a[2] && b[0]>b[2])
    {
      count++;
    }
    else if(a[0]<a[2] && b[0]<b[2])
    {
      count++;
    }
    else if(a[0]==a[2] && b[0]==b[2] )
    {
      count++;
    }
   else{}
    if(count==3) cout<<"FAIR"<<"\n";
    else cout<<"NOT FAIR"<<"\n";
    count=0;
  }
  return 0;
}
