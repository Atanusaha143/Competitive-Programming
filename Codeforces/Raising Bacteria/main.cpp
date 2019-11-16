// https://codeforces.com/contest/579/problem/A

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
    LLI t,count=0,bount=0;
    cin>>t;
        while(1)
        {
            if(t%2==1) count++;
            t/=2;
            if(t<=0) break;
        }
            cout<<count<<endl;

    return 0;
}
