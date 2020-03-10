#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
#define sz(x) x.size()
#define INF LONG_LONG_MAX
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

LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}

LL bigmod(LL base, LL power, LL mod)
{
    if(power==0) return 1;
    else if(power%2==1)
    {
        LL value1 = base % mod;
        LL value2 = (bigmod(base,power-1,mod))%mod;
        return (value1*value2)%mod;
    }
    else
    {
        LL value1 = (bigmod(base,power/2,mod))%mod;
        return (value1*value1)%mod;
    }
}

S str;
void convert(int n)
{
    for(int i=1; i<=n; i++)
    {
        stringstream sso;
        sso << i;
        S s;
        sso >> s;
        str += s;
    }
}



int main()
{
    int t;
    sfi(t);

    while(t--)
    {
        LL arr[10];
        mem(arr,0);
        int n;
        sfi(n);
        convert(n);
        for(int i=0; i<sz(str); i++)
        {
        if(str[i]=='0') arr[0]++;
        else if(str[i]=='1') arr[1]++;
        else if(str[i]=='2') arr[2]++;
        else if(str[i]=='3') arr[3]++;
        else if(str[i]=='4') arr[4]++;
        else if(str[i]=='5') arr[5]++;
        else if(str[i]=='6') arr[6]++;
        else if(str[i]=='7') arr[7]++;
        else if(str[i]=='8') arr[8]++;
        else if(str[i]=='9') arr[9]++;
        }

        for(int i=0; i<10; i++)
        {
            if(i==9)cout<<arr[i]<<NL;
            else cout<<arr[i]<<" ";
        }
        str.clear();
    }
}
