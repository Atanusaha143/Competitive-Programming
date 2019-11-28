// https://codeforces.com/contest/266/problem/A

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
    LL n,count=0;
    S s;
    cin>>n>>s;
    for(int i=0; i<n-1; i++)
    {
        if(s[i]==s[i+1])
        {
            count++;
        }
    }
    cout<<count<<endl;
}
