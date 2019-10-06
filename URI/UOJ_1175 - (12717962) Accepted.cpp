#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a[20],b[20];
    int i,j;
    for(i=0; i<20; i++)
    {
        cin>>a[i];
    }
    for(i=0, j=19; i<20; i++, j--)
    {
        b[i]=a[j];
    }
    for(i=0; i<20; i++)
    {
        cout<<"N["<<i<<"] = "<<b[i]<<endl;
    }
    return 0;
}
