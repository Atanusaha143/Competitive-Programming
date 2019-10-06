#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b=0;
    for(double i=1; i<=100; i++)
    {
        a = 1/i;
        b+=a;
    }
    cout<<fixed<<setprecision(2)<<b<<endl;
    return 0;
}
