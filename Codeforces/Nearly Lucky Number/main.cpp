// https://codeforces.com/problemset/problem/110/A

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
    IOS;
    LL n,count=0;
    cin>>n;
    while(n>0)
    {
        if(n%10==7 || n%10==4) count++;
        n/=10;
    }
    if(count==7 || count==4) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
