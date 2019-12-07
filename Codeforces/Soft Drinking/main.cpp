// https://codeforces.com/contest/151/problem/A

#include<bits/stdc++.h>
#define C            char
#define D            double
#define F            float
#define LL           long long
#define ULLI         unsigned long long int
#define LLI          long long int
#define LLD          long long double
#define LD           long double
#define S            string
#define PI          (2.0*acos(0.0))
#define IOS         ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    LL n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    cout<<min((k*l)/nl, min(c*d, p/np))/n;
    return 0;
}
