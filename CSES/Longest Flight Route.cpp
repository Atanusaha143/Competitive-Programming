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

struct Node
{
    int node_num, node_cost;
    Node(int _node_num, int _node_cost)
    {
        node_num = _node_num;
        node_cost = _node_cost;
    }
};

struct Edge
{
    int to, cost;
};

bool operator<(Node A, Node B)
{
    return A.node_cost > B.node_cost;
}

const int N = 1e5+10;
vector <Edge> adj[N];
int dist[N], parent[N];
int n,m;

void djk(int s)
{
    For(i,1,N-1) dist[i] = -1;
    dist[s] = 0;
    parent[s] = -1;

    priority_queue<Node> pq;
    pq.push({s,0});

    while(!pq.empty())
    {
        Node u = pq.top();
        pq.pop();

        int unode = u.node_num;
        int ucost = u.node_cost;

        if(ucost == dist[unode])
        {
            for(int i=0; i<sz(adj[unode]); i++)
            {
                int vnode = adj[unode][i].to;
                int vcost = adj[unode][i].cost;

                int newDistance = ucost + vcost;

                if(newDistance > dist[vnode])
                {
                    dist[vnode] = newDistance;
                    pq.push(Node(vnode,newDistance));
                    parent[vnode] = unode;
                }
            }
        }
    }
}

int main()
{
    Edge e;
    sfi2(n,m);
    For(i,1,m)
    {
        int from, to;
        sfi2(from,to);
        e.to = to;
        e.cost = 1;
        adj[from].PB(e);
    }

    djk(1);

    if(dist[n] == -1) printf("IMPOSSIBLE");
    else
    {
        printf("%d\n", dist[n]+1);
        vector <int> path;
        for(int v = n; v!=-1; v=parent[v])
            path.PB(v);

        reverse(all(path));

        for(int x : path)
            printf("%d ", x);
    }
    //main();
}

/*
5 5
1 2
2 5
1 3
3 4
4 5
*/
