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
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

const int N = 200+10;
const int MOD = 998244353;

vector <int> adj[N];
int arr[N][N], outdegree[N], parent[N];
bool visited[N];

void dfs(int s)
{
    if(visited[s]) return;
    visited[s] = true;
    for(int v : adj[s])
    {
        if(!visited[v])
        {
            dfs(v);
            parent[v] = s;
        }
    }
}

void clean(int n)
{
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
        outdegree[i] = 0;
        adj[i].clear();
        for(int j=1; j<=n; j++)
        {
            arr[i][j] = -1;
        }
    }
}

int main()
{
    int t; sfi(t); for(int tt=1; tt<=t; tt++){

        cin.ignore();

        int n;
        sfi(n);

        clean(n);

        for(int i=1; i<=n; i++)
        {
            int from, to, cost;
            sfi3(from,to,cost);
            arr[from][to] = cost;
            adj[from].PB(to);
            adj[to].PB(from);
            outdegree[from]++;
        }

        vector <int> vec;
        for(int i=1; i<=n; i++)
        {
            if(outdegree[i] == 0)
            {
                vec.PB(i);
            }
        }

        int mini = PINF;
        for(int i=0; i<vec.size(); i++)
        {
            for(int j=1; j<=n; j++) visited[j] = false;
            asort(adj[vec[i]]);
            dfs(vec[i]);
            parent[vec[i]] = -1;

            vector <int> path;
            for(int v=adj[vec[i]][1]; v!=-1; v=parent[v])
                path.PB(v);
            reverse(all(path));
            path.PB(vec[i]);

            int cost1 = 0;
            for(int j=0; j<path.size()-1; j++)
            {
                int u = path[j];
                int v = path[j+1];
                if(arr[u][v] == -1) cost1 += arr[v][u];
            }

            for(int j=1; j<=n; j++) visited[j] = false;
            dsort(adj[vec[i]]);
            dfs(vec[i]);
            parent[vec[i]] = -1;

            path.clear();
            for(int v=adj[vec[i]][1]; v!=-1; v=parent[v])
                path.PB(v);
            reverse(all(path));
            path.PB(vec[i]);

            int cost2 = 0;
            for(int j=0; j<path.size()-1; j++)
            {
                int u = path[j];
                int v = path[j+1];
                if(arr[u][v] == -1) cost2 += arr[v][u];
            }

            mini = min({mini,cost1,cost2});

        }

        if(mini == PINF) mini = 0;
        printf("Case %d: %d\n", tt, mini);

    }

    //main();
    return 0;
}

/*

https://lightoj.com/problem/one-way-roads

*/
