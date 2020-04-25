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

int main()
{
  int t;
  sfi(t);

  while(t--)
  {

    int n;
    sfi(n);

    int arr[n],brr[n];

    for(int i=1; i<=n; i++) sfi(arr[i]);

    sort(arr+1,arr+1+n);

    int odd=1;
    int even=n;

    for(int i=1; i<=n; i++)
    {
        if(i%2!=0)
        {
            brr[i]=arr[even];
            even--;
        }
        else
        {
            brr[i]=arr[odd];
            odd++;
        }
    }

    for(int i=n;i>=1;i--)
    {
        cout<<brr[i]<<" ";
    }

    cout<<NL;

  }
}
