// https://codeforces.com/contest/705/problem/A

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
    int n;
    cin>>n;
    int z = n-1;
        for(int i=1; i<=n; i++)
    {
        if(i%2!=0) cout<<"I hate ";
        else cout<<"I love ";
        if(z!=0) cout<<"that ";
        z--;
    }
    cout<<"it\n";
}
