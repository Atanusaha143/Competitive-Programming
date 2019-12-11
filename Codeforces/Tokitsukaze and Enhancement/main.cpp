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
    int rem = n%4;
    if(rem==1) cout<<"0 A"<<endl;
    else if(rem==2) cout<<"1 B"<<endl;
    else if(rem==3) cout<<"2 A"<<endl;
    else if(rem==0) cout<<"1 A"<<endl;
}
