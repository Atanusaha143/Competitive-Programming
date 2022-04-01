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

const int N = 2e5+10;
const int MOD = 998244353;

struct Node{
    int node_num, node_cost;
    Node(int  _node_num, int _node_cost){
        node_num = _node_num;
        node_cost = _node_cost;
    }
};

struct Edge{
    int to, cost;
};

bool operator<(Node A, Node B){
    return A.node_cost > B.node_cost;
}

vector <Edge> adj[N];
int dist[N];

void djk(int s)
{
    for(int i=0; i<N; i++) dist[i] = PINF;
    dist[s] = 0;

    priority_queue <Node> pq;
    pq.push(Node(s,0));

    while(!pq.empty())
    {
        Node u = pq.top(); pq.pop();
        int unode = u.node_num;
        int ucost= u.node_cost;

        if(ucost == dist[unode])
        {
            for(int i=0; i<adj[unode].size(); i++)
            {
                int vnode = adj[unode][i].to;
                int vcost = adj[unode][i].cost;
                int newDistance = ucost + vcost;
                if(newDistance < dist[vnode])
                {
                    dist[vnode] = newDistance;
                    pq.push(Node(vnode,newDistance));
                }
            }
        }
    }
}

int nodes, exit_node, timer;


int main()
{
    //WRITE;

    int t; sfi(t); for(int tt=1; tt<=t; tt++){

        if(tt != t) cin.ignore();

        sfi3(nodes,exit_node,timer);
        int edges;
        sfi(edges);
        Edge e;
        for(int i=1; i<=edges; i++)
        {
            int from, to, cost;
            sfi3(from,to,cost);
            e.to = from;
            e.cost = cost;
            adj[to].PB(e);
        }

        djk(exit_node);
        int cnt = 0;
        for(int i=1; i<=nodes; i++)
        {
            if(dist[i] <= timer)
            {
                cnt++;
            }
        }

        printf("%d\n", cnt);
        if(tt != t) printf("\n");

        for(int i=1; i<=nodes; i++)
        {
            if(adj[i].size())
            {
                adj[i].clear();
            }
        }

    }

    //main();
    return 0;
}

/*

https://onlinejudge.org/external/11/1112.pdf


*/

