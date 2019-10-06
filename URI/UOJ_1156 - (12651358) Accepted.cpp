#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b=0,c=1;
    for(double i=1; i<=39; i+=2)
    {
        a = i/c;
        b+=a;
        c*=2;
    }
    cout<<fixed<<setprecision(2)<<b<<endl;
    return 0;
}
