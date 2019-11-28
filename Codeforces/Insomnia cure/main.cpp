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
    IOS;
    LL k,l,m,n,d,count=0;
    cin>>k>>l>>m>>n>>d;
    LL arr[d+1];
    for(int i=1; i<=d; i++) arr[i]=i;
    for(int i=1; i<=d; i++) if(arr[i]%k==0) arr[i]=0;
    for(int i=1; i<=d; i++) if(arr[i]%l==0) arr[i]=0;
    for(int i=1; i<=d; i++) if(arr[i]%m==0) arr[i]=0;
    for(int i=1; i<=d; i++) if(arr[i]%n==0) arr[i]=0;
    for(int i=1; i<=d; i++) if(arr[i]>0) count++;
    cout<<d-count<<endl;
}
