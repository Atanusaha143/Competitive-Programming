// http://codeforces.com/contest/272/problem/A

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
    LL t,n,total_friends_finger=0,dima_needed_finger=0;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n;
        total_friends_finger+=n;
    }
    LL dima_with_friends = t+1;
    for(int i=1; i<=5; i++)
    {
        LL z = total_friends_finger + i;
        if(z%dima_with_friends != 1) dima_needed_finger++;
    }
    cout<<dima_needed_finger<<endl;
}
