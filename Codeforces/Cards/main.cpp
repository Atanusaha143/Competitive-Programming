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
    LL n,one=0,zero=0;
    cin>>n;
    S s;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='z') zero++;
        else if(s[i]=='n') one++;
    }
    if(one!=0)
    {
        for(int i=1; i<=one; i++) cout<<"1 ";
        for(int i=1; i<=zero; i++) cout<<"0 ";
    }
    else
    {
        for(int i=1; i<=zero; i++) cout<<"0 ";
        for(int i=1; i<=one; i++) cout<<"1 ";
    }
}
