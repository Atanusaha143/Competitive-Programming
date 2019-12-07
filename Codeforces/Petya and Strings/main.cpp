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
    S a,b;
    cin>>a>>b;
    LL x = a.size();
    LL y = b.size();
    C aa[x],bb[y];

    for(int i=0; i<x; i++)
    {
        aa[i]=tolower(a[i]);
        bb[i]=tolower(b[i]);
    }
    bool z = lexicographical_compare(aa,aa+x,bb,bb+y);
    bool z1 = lexicographical_compare(bb,bb+y,aa,aa+x);
    if(z==1) cout<<"-1\n";
    else if(z1==1) cout<<"1\n";
    else cout<<"0\n";
}
