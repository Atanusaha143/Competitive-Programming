// https://codeforces.com/problemset/problem/599/A

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
  int a,b,c;
  cin>>a>>b>>c;
  cout<<min(2*a+2*b,min(a+b+c,min(2*a+2*c, 2*b+2*c)));
   return 0;
}
