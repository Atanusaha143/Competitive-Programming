#include<iostream>
using namespace std;
int main()
{
    double a;
    int b=0;
    for(int i=0; i<6; i++)
    {
        cin>>a;
        if(a>0)
        b++;
    }
    cout<<b<<" valores positivos"<<endl;
    
    
    return 0;
}