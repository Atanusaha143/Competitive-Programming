#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x[10],a;
    cin>>a;
    for(int i=0; i<10; i++)
    {
        x[i]=a;
        cout<<"N["<<i<<"] = "<<a<<endl;
        a*=2;
    }
    return 0;
}
