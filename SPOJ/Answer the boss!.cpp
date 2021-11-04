#include <bits/stdc++.h>
using namespace std;

#define NL              '\n'
#define sz(x)           x.size()
#define PINF            INT_MAX
#define NINF            INT_MIN
#define PI              (2.0*acos(0.0))

#define sfi(x)          scanf("%d",&x)
#define sfi2(x,y)       scanf("%d %d",&x,&y)
#define sfi3(x,y,z)     scanf("%d %d %d",&x,&y,&z)
#define sfl(x)          scanf("%lld",&x)
#define sfl2(x,y)       scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z)     scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x)          scanf("%lf",&x);
#define sfd2(x,y)       scanf("%lf %lf",&x,&y);

#define max3(a,b,c)     max(a,max(b,c))
#define max4(a,b,c,d)   max(max3(a,b,c),d)
#define min3(a,b,c)     min(a,min(b,c))
#define min4(a,b,c,d)   min(a,min3(b,c,d))

#define PB              push_back
#define MP              make_pair
#define For(i, j, k)    for(int i = j; i <= k; i++)
#define Rof(i, j, k)    for(int i = j; i >= k; i--)
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define now             cout<<"Here"<<NL;

#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define READ            freopen("input.txt","r",stdin)
#define WRITE           freopen("output.txt","w",stdout)
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

LL gcd(LL a,LL b) { return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a,LL b) { return (a/gcd(a,b))*b; }

LL power_mod(LL base, LL power, LL mod)
{
    if(power==0) return 1LL;
    else if(power%2LL == 1)
    {
        LL p1 = base % mod;
        LL p2 = (power_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2LL == 0)
    {
        LL p1 = (power_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}

// Grid direction array [4]
int X[4]= {0,0,-1,1};
int Y[4]= {1,-1,0,0};
// Grid direction array [8]
int X8[8]= {0,0,1,-1,-1,1,1,-1};
int Y8[8]= {1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

const int N = 1e4+10;
//const LL MOD = 1000000007;
vector <int> adj[N];
int indegree[N], test;
vector <int> ans[N];

void kahn(int n)
{
    queue <PII> q;
    int cnt = 1;
    for(int i=0;i<n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push({i,1});
            ans[cnt].PB(i);
        }
    }

    while(!q.empty())
    {
        PII u = q.front();
        q.pop();

        for(auto v : adj[u.first])
        {
            indegree[v]--;
            if(indegree[v] == 0)
            {
                q.push({v,u.second+1});
                ans[u.second+1].PB(v);
            }
        }
    }

    For(i,1,n) asort(ans[i]);
    printf("Scenario #%d:\n",++test);

    For(i,1,n)
    {
        if(ans[i].size()==0)break;
        For(j,0,sz(ans[i])-1)
        {
            printf("%d %d\n", i, ans[i][j]);
        }
    }
}

void clean()
{
    For(i,0,N-1) adj[i].clear(),ans[i].clear();
    mem(indegree,0);
}

int main()
{
    int t;
    sfi(t);
    For(tt,1,t)
    {
        clean();
        int n,m;
        sfi2(n,m);
        For(i,1,m)
        {
            int u,v;
            sfi2(u,v);
            adj[v].PB(u);
            indegree[u]++;
        }

        kahn(n);
    }
    //main();
}

/*

2
5 6
2 0
2 4
1 4
1 2
3 2
4 0
5 4
1 0
2 0
3 2
4 2

*/

