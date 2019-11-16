// https://codeforces.com/contest/1257/problem/A

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

IOS;

    LL z;
    cin>>z;
    while(z--)
    {
        LL n,x,a,b;
        cin>>n>>x>>a>>b;
        LL tempo;
        if(a>b)
        {
            tempo=a;
            a=b;
            b=tempo;
        }
        while(true)
        {
            if(a==1 && b==n) break;
            if(x==0) break;
            if(a==1) {}
            else
            {
                a=a-1;
                x--;
            }
            if(x==0) break;
            if(b==n) {}
            else
            {
                b=b+1;
                x--;
            }
        }
        cout<<abs(a-b)<<endl;
    }
    return 0;
}
