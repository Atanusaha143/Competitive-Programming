#include<bits/stdc++.h>
#define ll long long
#define d double
#define s string
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t,a,b,c,x=0,y=0,y1=0,z=0,sum;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
       cin>>a>>b>>c;
        if(b==0 || a==0 && c==0 || b==1 && c==1) cout<<"0"<<"\n";
    else
    {
        while(b!=0)
        {
        if(b>=1 && c>=2)
        {
            y1++;
            z+=2;
            b--;
            c-=2;
        }
        else if(a>=1 && b>=2)
        {
            x++;
            y+=2;
            a--;
            b-=2;
        }
        else
        {
            break;
        }
        }
        sum = x+y+y1+z;
    cout<<sum<<"\n";
    }
    sum=0;
    x=0;
    y=0;
    y1=0;
    z=0;
    }
    return 0;
}
