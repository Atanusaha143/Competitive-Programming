#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,a=1,b=1,c=1;
    cin>>x;
    {
        for(int i=1; i<=x; i++)
        {
            cout<<a<<" "<<b<<" "<<c<<endl;
            a=a+1;
            b=(a*a);
            c=(a*a*a);
        }
    }
    return 0;
}
