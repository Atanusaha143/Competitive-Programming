#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    char a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }


    for(int i=0;i<n;i++)
    {
        if(a[i] == a[i+1])
            a[i]='1';
    }


    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>='a' && a[i]<='z')
            count++;

    }

    cout<<count<<endl;
    return 0;
}
