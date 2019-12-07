// https://codeforces.com/problemset/problem/339/A

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
    LL k=1;
    cin>>s;
    LL x = s.size();
    C arr[x];
    memset(arr,'0',sizeof(arr));
    LL pluss = x/2;
    sort(s.begin(),s.end());
    for(int i=pluss; i<x; i++)
    {
        arr[k] = s[i];
        k+=2;
    }
    for(int i=1; i<=k; i++)
    {
        if(arr[i]=='0') arr[i]='+';
    }
    for(int i=1; i<k-1; i++) cout<<arr[i];
}
