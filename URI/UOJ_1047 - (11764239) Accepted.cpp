#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    y=c-a;
    if(y<0)
    {
        y=24+(c-a);
    }
    x=d-b;
    if(x<0)
    {
        x=60+(d-b);
        y--;
    }
    if(c==a && d==b)
    {
        cout<<"O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)"<<endl;
    }
    else
    {
        cout<<"O JOGO DUROU "<<y<<" HORA(S) E "<<x<<" MINUTO(S)"<<endl;
    }
    
    return 0;
}