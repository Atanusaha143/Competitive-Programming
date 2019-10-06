#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,i;
    while(cin>>x)
    {
         if(x==0)
    {
        break;
    }
    else
    {
        for(i=1; i<x; i++)
            cout<<i<<" ";
    }
    cout<<x<<endl;
    }
    return 0;
}



