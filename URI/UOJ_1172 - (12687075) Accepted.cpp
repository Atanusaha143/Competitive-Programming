#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x[10],i;
    for(int i=0; i<10; i++)
    {
        cin>>x[i];
        if(x[i]>0)
        {
            cout<<"X["<<i<<"] = "<<x[i]<<endl;
        }
        else
        {
            cout<<"X["<<i<<"] = 1"<<endl;
        }
    }
    return 0;
}
