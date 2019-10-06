#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    float a, b, c, area, perm;
    cin>>a>>b>>c;
    
    
    
  
    if (a+b > c && a+c > b && b+c > a)
    {
        area=a+b+c;
       cout<<"Perimetro = "<<fixed << setprecision(1)<<area<<endl; 
    }
    else
    {
        perm=.5*(a+b)*c;
        cout<<"Area = "<<fixed << setprecision(1)<<perm<<endl;
    }
    
    return 0;
}