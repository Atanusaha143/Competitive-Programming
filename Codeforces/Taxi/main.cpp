//https://codeforces.com/contest/158/problem/B

#include<bits/stdc++.h>
#include<iomanip>
#define C char
#define D double
#define F float
#define LL long long
#define ULL unsigned long long
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

    IOS;

    LL t,a=0,b=0,c=0,d=0,ca=0,Ac=0;
    cin>>t;
    LL arr[t];
    for(int i=0; i<t; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<t; i++)
    {
        if(arr[i]==1) a++;
        if(arr[i]==2) b++;
        if(arr[i]==3) c++;
        if(arr[i]==4) d++;
    }
    if(c==a) {ca = (c+a)/4;
    D xc = (2*b)/4.00;
    LL x= ceil(xc);
    cout<<d+c+x;}
    else if(a>c) {Ac = a-c;
    D xc = ((2*b)+Ac)/4.00;
    LL x = ceil(xc);
    cout<<d+c+x;}
    else {D xc = (2*b)/4.00;
    LL x = ceil(xc);
    cout<<d+c+x;}
    return 0;
}
