#include<bits/stdc++.h>
#include<iomanip>
#define C char
#define D double
#define LL long long
#define ULL unsigned long long
#define LLI long long int
#define LLD long long double
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
//#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("in.txt","r",stdin)
#define WRITE  		freopen("out.txt","w",stdout)
using namespace std;

LLI dec(LLI x)
{
    LLI sum=0,z=0,a;
    while(x>0)
    {
        a = x%10;
        sum=sum+a*pow(2,z);
        x=x/10;
        z++;
    }
    return sum;
}
int main()
{
   //IOS;

    LLI a,b,c,d,e,f,g,h,i,n;
    C s;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>s>>b>>s>>c>>s>>d;
        cin>>e>>s>>f>>s>>g>>s>>h;

        if(a==dec(e) && b==dec(f) && c==dec(g) && d==dec(h))
            cout<<"Case "<<i<<": Yes\n";
        else cout<<"Case "<<i<<": No\n";
    }
   return 0;
}
