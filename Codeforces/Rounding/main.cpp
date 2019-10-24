#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    cin>>a;
    b = a%10;
    if(b<5) cout<<a-b;
    else if(b>5) cout<<(10-b)+a;
    else if(b==5) cout<<a+b;
    return 0;
}
