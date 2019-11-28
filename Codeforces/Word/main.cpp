// https://codeforces.com/contest/59/problem/A

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
    S s;
    cin>>s;
    S arr[100];
    LL lcount=0, ucount=0;
    LL x = s.size();
    for(int i=0; i<x; i++)
    {
        if(s[i]>='a' && s[i]<='z') lcount++;
        if(s[i]>='A' && s[i]<='Z') ucount++;
    }
    if(lcount>ucount)
    {
        for(int i=0; i<x; i++)
        {
            if(s[i]>='A' && s[i]<='Z') arr[i] = s[i]+32;
            else arr[i] = s[i];
        }
    }
    else if(ucount>lcount)
    {
        for(int i=0; i<x; i++)
        {
            if(s[i]>='a' && s[i]<='z') arr[i] = s[i]-32;
            else arr[i] = s[i];
        }
    }
    else
    {
                for(int i=0; i<x; i++)
        {
            if(s[i]>='A' && s[i]<='Z') arr[i] = s[i]+32;
            else arr[i] = s[i];
        }
    }
    for(int i=0; i<x; i++) cout<<arr[i];
    return 0;
}
