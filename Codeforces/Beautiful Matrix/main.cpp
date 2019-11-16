// https://codeforces.com/contest/263/problem/A

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
    LL row = 0, column = 0;
  LL arr[6],brr[6],crr[6],drr[6],err[6];
  for(int i=1; i<=5; i++)
  {
      cin>>arr[i]>>brr[i]>>crr[i]>>drr[i]>>err[i];
  }
  for(int i=1; i<=5; i++)
  {
      if(arr[i]==1) { row = i; column = 1; break;}
      else if(brr[i]==1) { row = i; column = 2; break;}
      else if(crr[i]==1) { row = i; column = 3; break;}
      else if(drr[i]==1) { row = i; column = 4; break;}
      else if(err[i]==1) { row = i; column = 5; break;}
  }
  cout<<abs((3-row))+abs((3-column))<<endl;
return 0;
}
