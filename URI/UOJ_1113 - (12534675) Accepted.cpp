#include <bits/stdc++.h>
using namespace std;
int main()
{
     int x,y;
    while(1)
    {
        cin>>x>>y;
        if(x==y)
        {
            break;
        }
        else if(x>=0 && y<x)
        {
            cout<<"Decrescente"<<endl;
        }
        else
        {
            cout<<"Crescente"<<endl;
        }
    }
 return 0;
}
