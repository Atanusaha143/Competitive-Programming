#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,arr[10],count=0,bount=0,k=0;
    cin>>t;
    int a[t];
    while(t--)
    {
        k++;
      for(int i=0; i<10; i++)
       {
          cin>>arr[i];
       }
     for(int j=0; j<9; j++)
      {
          if(arr[j]<arr[j+1])
        {
            count++;
        }
          else if(arr[j]>arr[j+1])
        {
            bount++;
        }
      }
    if(count==9 || bount==9)
    {
        a[k]=0;
    }
    else
    {
            a[k]=1;
    }
    count=0;
    bount=0;
    }
    cout<<"Lumberjacks:"<<endl;
    for(int i=1; i<=k; i++)
    {
        if(a[i]==0) cout<<"Ordered"<<endl;
        else cout<<"Unordered"<<endl;
    }
    return 0;
}


