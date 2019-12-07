//https://codeforces.com/problemset/problem/236/A

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
    LL x = s.size();
    map<C,LL>mp;
    LL count=0;
    for(int i=0; i<x; i++)
    {
        mp[s[i]]++;
    }
    LL z = mp.size();
    if(z%2==1) cout<<"IGNORE HIM!\n";
    else cout<<"CHAT WITH HER!\n";
    return 0;
}
