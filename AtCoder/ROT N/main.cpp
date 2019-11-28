#include<bits/stdc++.h>
#define C char
#define D double
#define F float
#define LL long long
#define ULLI unsigned long long int
#define LLI long long int
#define LLD long long double
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    LL n,y,z;
    cin>>n;
    S s;
    cin>>s;
    LL x = s.size();
    for(int i=0;i <x; i++)
    {
        if(s[i]+n>90)
        {
            y = s[i]+n;
            z = y-90;
            s[i]='A'+(z-1);
        }
        else
        {
            s[i]=s[i]+n;
        }
    }
    cout<<s;
    return 0;
}
