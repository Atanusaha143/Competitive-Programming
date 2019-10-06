#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a;
    double b,c,d,e;
    
    cin>>a;
    
    for(int i=0; i<a; i++)
    {
        cin>>b;
        cin>>c;
        cin>>d;
        
        e = ((b/10)*2)+((c/10)*3)+((d/10)*5);
        
        cout<<fixed<<setprecision(1)<<e<<endl;
    }
    return 0;
}