#include<iostream>
using namespace std;
int main()
{
    int n, pos=0, neg=0, ev=0, od=0;
    for(int i=1; i<6; i++)
    {
        cin>>n;
        if(n > 0)
        {
            pos++;
        }
        else
        {
            if( n!= 0)
            {
                neg++;
            }
        }
        if(n%2 == 0)
        {
            ev++;
        }
        else
        {
            od++;
        }
    }
    
    cout<<ev<<" valor(es) par(es)"<<endl;
    cout<<od<<" valor(es) impar(es)"<<endl;
	cout<<pos<<" valor(es) positivo(s)"<<endl;
    cout<<neg<<" valor(es) negativo(s)"<<endl;
 
 return 0;
}