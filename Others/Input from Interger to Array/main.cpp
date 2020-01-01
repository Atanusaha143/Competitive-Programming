#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll a,i=0,t=0;
    cin>>a;
    ll arr[10000];
    while(1)
    {
        arr[i]=a%10;
        a = a/10;
        i++;
        t++;
        if(a<10)
        {
            arr[i]=a;
            break;
        }
    }

    for(int i=t; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }
}
