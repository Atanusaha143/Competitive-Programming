// https://codeforces.com/problemset/problem/1080/A

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
    LL n,k,ans=0;
    cin>>n>>k;
    LL total_red = (2*n); LL total_green = (5*n); LL total_blue = (8*n);
    if(total_red%k!=0) ans+=(total_red/k)+1;
    else ans+=total_red/k;
    if(total_green%k!=0) ans+=(total_green/k)+1;
    else ans+=total_green/k;
    if(total_blue%k!=0) ans+=(total_blue/k)+1;
    else ans+=total_blue/k;
    cout<<ans<<endl;
}
