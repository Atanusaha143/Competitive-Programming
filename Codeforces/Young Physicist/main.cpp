// https://codeforces.com/contest/69/problem/A

#include<bits/stdc++.h>
#include<iomanip>
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
    IOS;
    LLI t,x,y,z,xx=0,yy=0,zz=0;
    cin>>t;
     for(int i=1; i<=t; i++)
     {
        cin>>x>>y>>z;
            xx+=x;
            yy+=y;
            zz+=z;
     }
     if(xx==0 && yy==0 && zz==0) cout<<"YES\n";
     else cout<<"NO\n";

    return 0;
}
