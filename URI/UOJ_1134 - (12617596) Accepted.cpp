#include <iostream>

using namespace std;

int main()
{
   int x=0,a=0,b=0,c=0;
   while(x!=4)
   {
   cin>>x;
       if(x==1)
       {
           a+=1;
       }
       if(x==2)
       {
           b+=1;
       }
       if(x==3)
       {
           c+=1;
       }
   }
   cout<<"MUITO OBRIGADO"<<endl;
   cout<<"Alcool: "<<a<<endl;
   cout<<"Gasolina: "<<b<<endl;
   cout<<"Diesel: "<<c<<endl;

   return 0;
}
