#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n, avg=0, t=0;
    int tNum=0;
    for(int i=0; i<6; i++)
    {
    cin>>n;
    if(n>0)
    {
        tNum += 1;
        t += n;
    }
    }
    avg= t/tNum;
    cout<<tNum<<" valores positivos"<<fixed<<setprecision(1)<<endl;
    cout<<avg<<fixed<<setprecision(1)<<endl;
    return 0;
}