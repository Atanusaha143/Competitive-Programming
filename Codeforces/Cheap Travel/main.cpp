// https://codeforces.com/problemset/problem/466/A

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
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int asum,bsum,csum;
    asum = n*a;
    bsum = ((n/m)+1)*b;
    csum = ((n/m)*b) + (n%m)*a;
    cout<<min(asum,min(bsum,csum));
}
