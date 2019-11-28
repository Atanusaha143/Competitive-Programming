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
    S s;
    cin>>s;
    if(s=="SUN") cout<<"7\n";
    else if(s=="MON") cout<<"6\n";
    else if(s=="TUE") cout<<"5\n";
    else if(s=="WED") cout<<"4\n";
    else if(s=="THU") cout<<"3\n";
    else if(s=="FRI") cout<<"2\n";
    else if(s=="SAT") cout<<"1\n";
    return 0;
}
