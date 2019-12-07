//https://codeforces.com/contest/996/problem/A

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
    LL one=1,five=5,ten=10,twenty=20,hundred=100,n,count=0;
    cin>>n;
    if(n>=hundred)
    {
        while(n!=0)
        {
          if(n>=hundred) {n-=hundred; count++;}
          else if(n>=twenty) {n-=twenty; count++;}
          else if(n>=ten) {n-=ten; count++;}
          else if(n>=five) {n-=five; count++;}
          else if(n!=0) {n--; count++;}
        }
        cout<<count<<endl;
    }
    else
    {
        while(n!=0)
        {
            if(n>=twenty) {n-=twenty; count++;}
          else if(n>=ten) {n-=ten; count++;}
          else if(n>=five) {n-=five; count++;}
          else if(n!=0) {n--; count++;}
        }
        cout<<count<<endl;
    }
}
