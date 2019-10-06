#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    double avg,n=0,count=0;
    while(1)
    {
        cin>>x;
        if(x<0)
        {
            break;
        }
        else
        {
            n+=x;
            count+=1;
        }
    }
    if(count==0)
    {
      avg = 0;
    }
    else
    {
      avg = (n/count);
      cout<<fixed<<setprecision(2)<<avg<<endl;
    }
    return 0;
}
