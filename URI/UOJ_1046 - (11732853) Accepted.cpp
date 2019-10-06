#include<iostream>
using namespace std;

int main()
{
    int a,b,x,y;
    cin>>a>>b;
    
    if(a>=b)
    {
        x=(24-a)+b;
        cout<<"O JOGO DUROU "<<x<<" HORA(S)"<<endl;
    }
    else
    {
        y=(b-a);
        cout<<"O JOGO DUROU "<<y<<" HORA(S)"<<endl;
    }
    return 0;
    
}