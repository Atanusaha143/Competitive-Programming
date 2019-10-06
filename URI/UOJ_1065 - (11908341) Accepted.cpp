#include<iostream>
using namespace std;
int main()
{
    int n, ev=0;
    for(int i=1; i<6; i++)
    {
        cin>>n;
        
        if(n%2 == 0)
        {
            ev++;
        }
    }
    
    cout<<ev<<" valores pares"<<endl;
 
 return 0;
}