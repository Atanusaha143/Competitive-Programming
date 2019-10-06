#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,a=1,b=2,c=3;
    cin>>x;
    {
        for(int i=1; i<=x; i++)
        {
            cout<<a<<" "<<b<<" "<<c<<" PUM"<<endl;
            a+=4;
            b+=4;
            c+=4;
        }
    }
    return 0;
}
