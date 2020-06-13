#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define sz(x) x.size()
#define INF LONG_MAX
#define IINF LLONG_MAX
#define PI (2.0*acos(0.0))

#define sfi(x) scanf("%d",&x)
#define sfi2(x,y) scanf("%d %d",&x,&y)
#define sfi3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sfl(x) scanf("%lld",&x)
#define sfl2(x,y) scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x) scanf("%lf",&x);
#define sfd2(x,y) scanf("%lf %lf",&x,&y);

#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(a,min3(b,c,d))

#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define For(i, j, k) for(int i = j; i <= k; i++)
#define Rof(i, j, k) for(int i = j; i >= k; i--)
#define all(x) x.begin(),x.end()
#define asort(x) sort(all(x));
#define dsort(x) sort(all(x), greater<int>())
#define unq(x) x.erase(unique(x.begin(),x.end()),x.end())

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

LL gcd(LL a,LL b) { return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a,LL b) { return (a/gcd(a,b))*b; }

int main()
{
    int t;
    sfi(t);

    while(t--)
    {
        int n;
        sfi(n);
        for(int i=n+1; i<2e9; i++)
        {
            string str = to_string(i);
            int len = sz(str);
            int sum = 0;
            For(i,0,len-1) sum += str[i]-'0';

            int num = i;
            vector <int> factors;
            while(num%2==0)
            {
                num /= 2;
                factors.PB(2);
            }
            int limit = sqrt(num);
            for(int j=3; j<=limit; j+=2)
            {
                while(num%j==0)
                {
                    num /= j;
                    factors.PB(j);
                }
            }
            if(num>1) factors.PB(num);

            LL dum = 0;
            if(sz(factors)!=1)
            {
                for(int k=0; k<sz(factors); k++)
                {
                    string str1 = to_string(factors[k]);
                    if(sz(str1)==1) dum += factors[k];
                    else
                    {
                        for(int k=0; k<sz(str1); k++)
                            dum += str1[k]-'0';
                    }
                }
            }

            if(sum==dum)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
}
