//https://codeforces.com/contest/1257/problem/B

#include<bits/stdc++.h>
#include<iomanip>
#define C char
#define D double
#define LL long long
#define ULL unsigned long long
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

    //IOS;

    LL z;
    cin>>z;

    while(z--)
    {
        LL x,y;
        cin>>x>>y;
        if(x==y) cout<<"YES\n";
        else if(x>y) cout<<"YES\n";
        else if(x<y)
        {
            if(x%2==0 && x>=4) cout<<"YES\n";
            else if(x>=4) cout<<"YES\n";
            else if(x==2 && y==3) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
