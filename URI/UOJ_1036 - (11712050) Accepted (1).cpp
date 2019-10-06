#include<iostream>
#include<cmath> 
#include<iomanip>
using namespace std;

int main()

{
  double a , b , c ,r1 , r2 , sq ;
  cin >> a >> b >> c ;
  
  sq = sqrt((b*b) - (4*a*c));
  r1 = (-b+sq)/(2*a);
  r2 = (-b-sq)/(2*a);
  
if (a!=0 && sq >0)
  {
    cout << "R1 = "<<fixed<<setprecision(5)<<r1<<endl;
    cout << "R2 = "<<fixed<<setprecision(5)<<r2<<endl;
  }
else
{
    cout<< "Impossivel calcular" << endl;
}
    
return 0;
}