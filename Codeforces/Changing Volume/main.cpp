// https://codeforces.com/contest/1255/problem/A

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
    LL t;
    cin>>t;
    while(t--)
    {
        LL a,b;
        LL bum=0,dum=0,sum=0;
        cin>>a>>b;
        if(a==b) cout<<"0\n";
        else
        {
            LL x = abs(a-b);
            if(x==1) cout<<"1\n";
            else if(x==2) cout<<"1\n";
            else if(x==3 || x==4) cout<<"2\n";
            else if(x==5) cout<<"1\n";
                else
            {
                if(x%5==0)
                {
                    bum = x/5;
                    cout<<bum<<endl;
                }
                else
                {
                    bum = x/5;
                    LL y = x - (bum*5);
                    if(y<=2)
                    cout<<bum+1<<endl;
                    else if(y>2) cout<<bum+2<<endl;
                }

            }
        }
    }
    return 0;
}
