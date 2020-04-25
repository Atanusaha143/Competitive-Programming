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
#define pb push_back
#define asort(x) sort(x.begin(), x.end())
#define dsort(x) sort(x.begin(), x.end(), greater<int>())
#define unq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define mem(ara,val) memset(ara,val,sizeof(ara))
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

LL gcd(LL a,LL b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
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
        LL value1 = base % mod; LL value2 = (bigmod(base,power-1,mod))%mod;
        return (value1*value2)%mod;
    }
    else
    {
        LL value1 = (bigmod(base,power/2,mod))%mod;
        return (value1*value1)%mod;
    }
}


int main()
{

    int n, s;
    sfi2(n,s);

    S maxi="";

    if(n==1 && s==0) cout<<"0 0";

    else if(n>1 && s==0) cout<<"-1 -1";

    else
    {
        while(n--)
        {
            int x = min(s,9);

            S str = to_string(x);

            maxi += str;

            s -= x;
        }

        if(s>0)
        {
            cout<<"-1 -1";

            return 0;
        }

        S mini = maxi;

        reverse(mini.begin(), mini.end());

        if(mini[0]=='0')
        {
            int pos = 0;

            while(mini[pos]=='0') pos++;

            mini[0]++;

            mini[pos]--;

            cout<<mini<<" "<<maxi;
        }
        else
        {
            cout<<mini<<" "<<maxi;
        }
    }
}
