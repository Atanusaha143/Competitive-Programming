#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string

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
typedef pair<int, int> PII;

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

map <C,int> smp,tmp;

bool Auto(S s, S t)
{
    int sz_s = sz(s), sz_t = sz(t);
    int idx = 0;
    for(int i=0; i<sz_t; i++)
    {
        int j = idx;
        bool check = false;
        for(; j<sz_s; j++)
        {
            if(t[i]==s[j])
            {
                check = true;
                idx = j+1;
                break;
            }
        }
        if(!check) return false;
    }
    return true;
}

bool Array(S s, S t)
{
    sort(all(s)); sort(all(t));
    int sz_s = sz(s), sz_t = sz(t);
    if(sz_s!=sz_t) return false;
    else
    {
        For(i,0,sz_s-1)
        if(s[i]!=t[i])
            return false;
        return true;
    }
}

bool Both(S s, S t)
{
    int sz_t = sz(t);
    For(i,0,sz_t-1)
    {
        if(smp[t[i]]<tmp[t[i]])
            return false;
    }
    return true;
}

int main()
{
    S s,t;
    cin>>s>>t;
    int sz_s = sz(s), sz_t = sz(t);
    For(i,0,sz_s-1)
    smp[s[i]]++;
    For(i,0,sz_t-1)
    tmp[t[i]]++;

    bool checkAuto = Auto(s,t);
    if(checkAuto) printf("automaton");
    else
    {
        bool checkArray = Array(s,t);
        if(checkArray) printf("array");
        else
        {
            bool checkBoth = Both(s,t);
            if(checkBoth) printf("both");
            else printf("need tree");
        }
    }
}
