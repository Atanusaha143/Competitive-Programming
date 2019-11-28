// https://codeforces.com/problemset/problem/266/B

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
    LL n,t;
    cin>>n>>t;
    S s;
    cin>>s;
    while(t--)
    {
            for(int i=0; i<n; i++)
    {
        if(s[i]=='B' && s[i+1]=='G')
        {
            swap(s[i],s[i+1]);
            i++;
        }
    }
    }

    for(int i=0; i<n; i++) cout<<s[i];
    return 0;
}
