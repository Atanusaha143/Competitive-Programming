// https://codeforces.com/contest/785/problem/A

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
    LL n,ans=0;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s=="Tetrahedron") ans+=4;
        else if(s=="Cube") ans+=6;
        else if(s=="Octahedron") ans+=8;
        else if(s=="Dodecahedron") ans+=12;
        else if(s=="Icosahedron") ans+=20;
    }
    cout<<ans<<endl;
}
