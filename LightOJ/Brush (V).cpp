#include <bits/stdc++.h>
using namespace std;

#define NL '\n'
#define sz(x) x.size()
#define PINF INT_MAX
#define NINF INT_MIN
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
#define PF push_front
#define MP make_pair
#define For(i, j, k) for(int i = j; i <= k; i++)
#define Rof(i, j, k) for(int i = j; i >= k; i--)
#define all(x) x.begin(),x.end()
#define asort(x) sort(all(x));
#define dsort(x) sort(all(x), greater<int>())
#define unq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define now cout<<"Here"<<NL;

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
bool compare(string &str1, string &str2) { return str1.size() > str2.size(); }

// Grid direction array [4]
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
// Grid direction array [8]
int X8[8]={0,0,1,-1,-1,1,1,-1};
int Y8[8]={1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

struct Edge
{
    LL u,v,w;
};

const LL N = 1005;
vector <Edge> adj;
LL dist[N], n, m;

void bf(LL s)
{
    for(int i=0; i<N; i++) dist[i] = 1e17;
    dist[s] = 0;

    for(int i=0; i<n; i++)
    {
        bool change = false;
        for(int j=0; j<2*m; j++)
        {
            LL unode = adj[j].u;
            LL vnode = adj[j].v;
            LL uvCost = adj[j].w;

            LL newDistance = dist[unode] + uvCost;
            if(newDistance < dist[vnode])
            {
                dist[vnode] = newDistance;
                change = true;
            }
        }
        if(!change) break;
    }
}

void clean()
{
    adj.clear();
    mem(dist,0);
}

int main()
{
    int t;
    sfi(t);
    for(int tt=1; tt<=t; tt++)
    {
        clean();

        sfl2(n,m);
        Edge e;
        for(int i=0; i<m; i++)
        {
            sfl3(e.u,e.v,e.w);
            adj.PB(e);
            swap(e.u,e.v);
            adj.PB(e);
        }

        bf(1LL);

        if(dist[n] == 1e17) printf("Case %d: Impossible\n", tt);
        else printf("Case %d: %lld\n", tt , dist[n]);
    }
    //main();
}

/*
2

3 2
1 2 50
2 3 10

3 1
1 2 40

*/
