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
    int n; cin>>n;
    C c[n+1];
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=1; i<=n; i++)
    {
        char k = c[i*(i+1)/2];
        int l = i*(i+1)/2;
        if(l==n) {cout<<k; break;}
        else cout<<k;
    }
}
