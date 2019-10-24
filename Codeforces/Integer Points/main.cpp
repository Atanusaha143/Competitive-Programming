#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,x,y,t,v,e1=0,e2=0,o1=0,o2=0;
    cin>>a;
    for(int i=0; i<a; i++)
    {
        cin>>x;
        for(int i=0; i<x; i++)
        {
            cin>>t;
            if(t%2==0) e1++;
            else o1++;
        }
        cin>>y;
        for(int i=0; i<y; i++)
        {
            cin>>v;
            if(v%2==0) e2++;
            else o2++;
        }
        long long int ans= (e1*e2)+(o1*o2);
        cout<<ans<<endl;
       e1=0,e2=0,o1=0,o2=0;
    }
    return 0;
}
