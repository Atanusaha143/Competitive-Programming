// https://codeforces.com/contest/791/problem/A

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
    int a,b,count=0;
    cin>>a>>b;
    while(1)
    {
        a*=3; b*=2;
        if(a<=b) count++;
        else if(a>b) break;
    }
    cout<<count+1<<endl;
}
