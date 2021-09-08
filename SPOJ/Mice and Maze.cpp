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

int d4x[] = {0,1,0,-1}; // 4 direction array
int d4y[] = {-1,0,1,0};
int d8x[] = {0,1,0,-1,1,-1,1,-1}; // 8 direction array
int d8y[] = {1,0,-1,0,1,-1,-1,1};
int kx[] = {1,2,2,1,-1,-2,-2,-1}; // knights move
int ky[] = {2,1,-1,-2,-2,-1,1,2};

struct Node
{
    LL node_num, node_cost;
    Node(LL _node_num, LL _node_cost)
    {
        node_num = _node_num;
        node_cost = _node_cost;
    }
};

struct Edge
{
    LL to, cost;
};

bool operator<(Node A, Node B)
{
    return A.node_cost > B.node_cost;
}

const LL N = 105;
vector <Edge> adj[N];
LL dist[N];
LL n,e,t,m;

void djk(LL s)
{
    for(int i=0; i<N; i++) dist[i] = 1e17;
    dist[s] = t;

    priority_queue<Node> pq;
    pq.push(Node(s,0));

    while(!pq.empty())
    {
        Node u = pq.top();
        pq.pop();

        LL unode = u.node_num;
        LL ucost = u.node_cost;

        for(auto x : adj[unode])
        {
            LL vnode = x.to;
            LL vcost = x.cost;

            LL newDistance = ucost + vcost;

            if(newDistance < dist[vnode])
            {
                dist[vnode] = newDistance;
                pq.push(Node(vnode,newDistance));
            }
        }
    }
}

int main()
{
    sfl3(n,e,t);
    sfl(m);
    Edge edg;

    for(int i=0; i<m; i++)
    {
        LL from,to,cost;
        sfl3(from,to,cost);
        edg.to = to;
        edg.cost = cost;
        adj[from].PB(edg);
        edg.to = from;
        adj[to].PB(edg);
    }

    djk(e);

    int cnt = 0;
    for(int i=0; i<n; i++)
        if(dist[i+1] <= t)
        cnt++;

    printf("%d\n", cnt);
    //main();
}

/*

4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1

*/

