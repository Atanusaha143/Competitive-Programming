#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int x,y,i,j;
    long long int fact1,fact2;
    fact1 = fact2 = 1;
    while(cin>>x)
    {
        cin>>y;
            for(i=1; i<=x; i++)
    {
            fact1*=i;
    }
      for(j=1; j<=y; j++)
    {
            fact2*=j;
    }
     long long int sumOFfact =  fact1 + fact2;
     cout<<sumOFfact<<endl;
     fact1 = fact2 = 1;
    }
    return 0;
}
