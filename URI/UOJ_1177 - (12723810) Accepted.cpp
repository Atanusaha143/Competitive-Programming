#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,i,a;
    cin>>x;
    for( i=0, a=0; i<1000; i++)
    {
        cout<<"N["<<i<<"] = "<<a<<endl;
        a++;
        if(a==x)
            a=0;
    }
    return 0;
}
