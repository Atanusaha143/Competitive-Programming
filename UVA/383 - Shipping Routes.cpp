#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
//typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// *find_by_order = value of an index, order_of_key = index of a value where it should be
//typedef tree<PII, null_type, greater<PII>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }

LL gcd(LL a,LL b) { return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a,LL b) { return (a/gcd(a,b))*b; }

//LL power_mod(LL base, LL power, LL mod)
//{
//    if(power==0) return 1LL;
//    else if(power%2LL == 1)
//    {
//        LL p1 = base % mod;
//        LL p2 = (power_mod(base,power-1,mod))%mod;
//        p1 = (LL)(p1*p2);
//        return p1%mod;
//    }
//    else if(power%2LL == 0)
//    {
//        LL p1 = (power_mod(base,power/2LL,mod))%mod;
//        p1 = (LL)(p1*p1);
//        return p1%mod;
//    }
//}

//LL original_power(LL base, LL power)
//{
//    if(power==0) return 1LL;
//    else if(power%2LL == 1)
//    {
//        LL p1 = base;
//        LL p2 = (original_power(base,power-1));
//        p1 = (LL)(p1*p2);
//        return p1;
//    }
//    else if(power%2LL == 0)
//    {
//        LL p1 = (original_power(base,power/2LL));
//        p1 = (LL)(p1*p1);
//        return p1;
//    }
//}

//// Grid direction array [4]
//int X[4]= {0,0,-1,1};
//int Y[4]= {1,-1,0,0};
//// Grid direction array [8]
//int X8[8]= {0,0,1,-1,-1,1,1,-1};
//int Y8[8]= {1,-1,0,0,-1,-1,1,1};
//// Knight Direction Array
//int KX[8] = {1,1,2,2,-1,-1,-2,-2};
//int KY[8] = {2,-2,1,-1,2,-2,1,-1};

const int N = 2e5+10;
const int MOD = 998244353;

int n,m,p;
map <string,int> composer;
vector <int> adj[N];
bool visited[N];
int dist[N];

int bfs(int s, int d)
{
    visited[s] = true;
    dist[s] = 0;
    queue <int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v : adj[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if(!visited[d]) return 0;
    return (int)dist[d];
}

void clean(int n)
{
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
        dist[i] = 0;
    }
}

int main()
{
    cout<<"SHIPPING ROUTES OUTPUT"<<NL;
    int t; sfi(t); for(int tt=1; tt<=t; tt++){

        sfi3(n,m,p);
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            string str;
            cin>>str;
            if(composer.find(str) == composer.end())
            {
                composer[str] = ++cnt;
            }
        }

        for(int i=1; i<=m; i++)
        {
            string u, v;
            cin>>u>>v;
            int x = composer[u];
            int y = composer[v];
            adj[x].PB(y);
            adj[y].PB(x);
        }

        cout<<NL<<"DATA SET  "<<tt<<NL<<NL;

        for(int i=1; i<=p; i++)
        {
            int x;
            string s, d;
            cin>>x>>s>>d;
            int source = composer[s];
            int destination = composer[d];
            int ans = bfs(source,destination);
            if(ans == 0) cout<<"NO SHIPMENT POSSIBLE"<<NL;
            else
            {
                ans = ans * x * 100;
                cout<<"$"<<ans<<NL;
            }
            clean(cnt);
        }

        for(int i=1; i<=cnt; i++)
        {
            adj[i].clear();
        }

        composer.clear();
    }

    cout<<NL<<"END OF OUTPUT"<<NL;

    //main();
    return 0;
}

/*

https://onlinejudge.org/external/3/383.pdf

*/