#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
#define PI (2.0*acos(0.0))
#define sfi(x) scanf("%d",&x)
#define sfi2(x,y) scanf("%d %d",&x,&y)
#define sfi3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sfl(x) scanf("%lld",&x)
#define sfl2(x,y) scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x) scanf("%lf",&x);
#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define mem(ara,val) memset(ara,val,sizeof(ara))
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

/*LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}*/

int main()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        int x = n/2;
        if(x>9)
        {
            cout<<n<<NL;
            for(int i=1; i<=n; i++) cout<<1<<" ";
        }
        else
        {
            cout<<2<<NL;
            for(int i=1; i<=2; i++) cout<<x<<" ";
        }
    }
    else if(n%3==0)
    {
        int x = n/3;
        if(x>9)
        {
            cout<<n<<NL;
            for(int i=1; i<=n; i++) cout<<1<<" ";
        }
        else
        {
            cout<<3<<NL;
            for(int i=1; i<=3; i++) cout<<x<<" ";
        }
    }
    else if(n%5==0)
    {
        int x = n/5;
        if(x>9)
        {
            cout<<n<<NL;
            for(int i=1; i<=n; i++) cout<<1<<" ";
        }
        else
        {
            cout<<5<<NL;
            for(int i=1; i<=5; i++) cout<<x<<" ";
        }
    }
    else
    {
        cout<<n<<NL;
        for(int i=1; i<=n; i++) cout<<1<<" ";
    }
}

/// OR ///

/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<10)
    {
        cout<<1<<endl;
        cout<<n;
    }
    else
    {
        cout<<n<<endl;
        for(int i=1; i<=n; i++) cout<<1<<" ";
    }
}*/


/// OR ///

/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<n<<endl;
    for(int i=1; i<=n; i++) cout<<1<<" ";
}
*/
