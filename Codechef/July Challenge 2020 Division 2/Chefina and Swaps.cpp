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

bool checkOne(map <int,int> mp)
{
    for(auto x : mp)
    {
        int freq = x.se;
        if(freq%2)
            return true;
    }
    return false;
}

int main()
{
    int t;
    sfi(t);

    while(t--)
    {
        int n;
        sfi(n);

        vector <int> a(n),b(n);
        map <int,int> mp, amap, bmap;

        For(i,0,n-1) sfi(a[i]), mp[a[i]]++, amap[a[i]]++;
        For(i,0,n-1) sfi(b[i]), mp[b[i]]++, bmap[b[i]]++;

        if(checkOne(mp)) cout<<-1<<NL;
        else
        {
            asort(a); asort(b);
            if(a==b)
            {
                cout<<0<<NL;
                continue;
            }

            int min1 = *min_element(all(a));
            int min2 = *min_element(all(b));
            int mini = min(min1,min2);

            map <int,int> mp1,mp2;

            for(auto x : amap)
            {
                int idx = x.fi;
                int val = x.se;
                if(val > bmap[idx]) mp1[idx] = (val-bmap[idx]) / 2;
            }
            for(auto x : bmap)
            {
                int idx = x.fi;
                int val = x.se;
                if(val > amap[idx]) mp2[idx] = (val-amap[idx]) / 2;
            }

            vector <int> vec1, vec2;

            for(auto x : mp1)
                for(int j=0; j<x.se; j++)
                    vec1.PB(x.fi);

            for(auto x : mp2)
                for(int j=0; j<x.se; j++)
                    vec2.PB(x.fi);

            asort(vec1);
            dsort(vec2);

            LL cost = 0;
            For(i,0,sz(vec1)-1)
            {
                int val1 = vec1[i];
                int val2 = vec2[i];
                cost += min3(2*mini, val1, val2);
            }

            printf("%lld\n",cost);
        }
    }
}

