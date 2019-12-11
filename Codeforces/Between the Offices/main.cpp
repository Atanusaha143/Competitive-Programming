// https://codeforces.com/contest/867/problem/A

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
    int n,seattle=0,san_francisco=0;
    cin>>n;
    S s;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='S' && s[i+1]=='F') seattle++;
        else if(s[i]=='F' && s[i+1]=='S') san_francisco++;
    }
    if(seattle>san_francisco) cout<<"YES\n";
    else cout<<"NO\n";
}
