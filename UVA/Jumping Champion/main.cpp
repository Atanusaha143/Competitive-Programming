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

const int n = 1e6;
bool arrPrime[n+1];
vector <int> vecPrimes;
void isPrime()
{
    mem(arrPrime,true);

    int limit = sqrt(n);
    arrPrime[0] = false, arrPrime[1] = false, arrPrime[2] = true;
    for(int i=4; i<=n; i+=2) arrPrime[i] = false;
    vecPrimes.PB(2);
    for(int i=3; i<=n; i+=2)
    {
        if(arrPrime[i])
        {
            vecPrimes.PB(i);
            if(i<=limit)
            {
                for(LL j=i*i; j<=n; j+=(2*i))
                {
                    arrPrime[j] = false;
                }
            }
        }
    }
}

int main()
{
    isPrime();

    int t;
    sfi(t);

    while(t--)
    {
        int l,r;
        sfi2(l,r);
        vector <int> currPrimes;
        for(int i=0; i<sz(vecPrimes); i++)
            if(vecPrimes[i]>=l and vecPrimes[i]<=r) currPrimes.PB(vecPrimes[i]);

        if(sz(currPrimes)<2) printf("No jumping champion\n");
        else
        {
            map <int,int> mp;
            for(int i=1; i<sz(currPrimes); i++)
                mp[currPrimes[i]-currPrimes[i-1]]++;

            vector <int> diffs;
            for(auto it=mp.begin(); it!=mp.end(); it++)
                diffs.PB(it->se);

            int maxi = *max_element(all(diffs));
            if(count(all(diffs),maxi)>1) printf("No jumping champion\n");
            else
            {
                for(auto it=mp.begin(); it!=mp.end(); it++)
                    if(it->se==maxi)
                {
                    printf("The jumping champion is %d\n",it->fi);
                    break;
                }
            }
        }
    }
}
