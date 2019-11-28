// https://codeforces.com/contest/808/problem/A

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
    IOS;
        LL num=0,dum=0;
        S s,cp;
        cin>>s;
        LL x = s.size();
        for(int i=0; i<x; i++) cp[i]='0';
        cp[0] = s[0]+1;
        for(int i=0; i<x; i++)
        {
            LL a = s[i]-'0';
            num = num + a;
            if(i!=x-1)
            num = num * 10;
        }

        for(int i=0; i<x; i++)
        {
            LL a = cp[i]-'0';
            dum = dum + a;
            if(i!=x-1)
            dum = dum * 10;
        }
        cout<<dum-num;
    return 0;
}
