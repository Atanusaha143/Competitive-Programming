#include<iostream>
using namespace std;

int main()
{
    int x, x1, in = 0, out = 0;
    
    cin>>x;
    
    for(int i=0; i<x; i++)
    {
        cin>>x1;
        
        if( x1 >= 10 && x1 <= 20)
        {
            in++;
        }
        else
        {
            out++;
        }
    }
    cout<< in <<" in"<<endl;
    cout<< out <<" out"<<endl;
}