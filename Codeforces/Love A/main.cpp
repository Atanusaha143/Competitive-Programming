// https://codeforces.com/contest/1146/problem/A

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
#define cnt long long count=0
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    S s;
    int a=0;
    cin>>s;
    int x = s.size();
    for(int i=0; i<x; i++)
    {
        if(s[i]=='a') a++;
    }
    int z = x-a;
    if(a==1) cout<<"1\n";
    else if(a>z) cout<<x<<endl;
    else
    {
        while(x>=a) x--;
            cout<<a+x<<endl;
    }
}
