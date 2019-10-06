#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  float a, x1, x2, per;
  cin>>a;

 if(a<=400)
    {
      per=15;
      x1=a*per/100;
      x2=(x1+a);
     }
 
    else if (a>400.01&&a<800)
     {
      per=12;
      x1=a*per/100;
      x2=(x1+a);
     }
  
     else if (a>=800&&a<=1200)
     {
      per=10;
      x1=a*per/100;
      x2=(x1+a);
     }
   
      else if(a>=1200&&a<=2000)
     {
      per=7;
      x1=a*per/100;
      x2=(x1+a);
     }
    
      else
     {
      per=4;
      x1=a*per/100;
      x2=(x1+a);
     }
     
     cout << "Novo salario: " << fixed << setprecision(2) <<x2<< endl;
     cout << "Reajuste ganho: " << fixed << setprecision(2) << (x2 - a) << endl;
     cout << "Em percentual: " << fixed << setprecision(0) <<per<<" %" << endl;
     
     
    return 0;
}