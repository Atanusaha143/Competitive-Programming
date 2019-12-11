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
    LL t;
    cin>>t;
    while(t--)
    {
        LL a;
        cin>>a;
        if(a%2==1) cout<<"1"<<endl;
        else if(a>2 && a%2==0) cout<<"0"<<endl;
        else if(a==2) cout<<"2"<<endl;
    }
}
