#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define PI              (2.0*acos(0.0))
#define PB              push_back
#define MP              make_pair
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
#define now             cerr<<"Here"<<endl;
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

///------------------------------------------------------------------------------------------------------------------------

const int N = 1e6 + 10;
const int MOD = 1000000007;

int n, m;
int dist1[N], dist2[N];

struct Node{
    int node_num, node_cost;
    Node(int _node_num, int _node_cost)
    {
        node_num = _node_num;
        node_cost = _node_cost;
    }
};

struct Edge{
    int to, cost;
};

bool operator<(Node A, Node B)
{
    return A.node_cost > B.node_cost;
}

vector <Edge> adj[N];

void dijkstra(int s)
{
    for(int i=0; i<N; i++)
    {
        dist2[i] = INT_MAX;
    }
    dist2[s] = 0;

    priority_queue <Node> pq;
    pq.push(Node(s,0));

    while(!pq.empty())
    {
        Node u = pq.top(); pq.pop();
        int unode = u.node_num;
        int ucost = u.node_cost;

        if(ucost == dist2[unode])
        {
            for(auto x : adj[unode])
            {
                int vnode = x.to;
                int vcost = x.cost;

                int newDistance = ucost + vcost;
                if(newDistance < dist2[vnode])
                {
                    dist2[vnode] = newDistance;
                    pq.push(Node(vnode,newDistance));
                }
            }
        }
    }
}

void clean(int n)
{
    for(int i=0; i<=n; i++)
    {
        if(adj[i].size()) adj[i].clear();
    }
}

void solve(int casenum)
{

    cin>>n>>m;

    Edge e;
    for(int i=1,u,v,w; i<=m; i++)
    {
        cin>>u>>v>>w;
        e.to = v;
        e.cost = w;
        adj[u].PB(e);
        e.to = u;
        adj[v].PB(e);
    }

    dijkstra(1);
    for(int i=1; i<=n; i++)
    {
        dist1[i] = dist2[i];
    }
    dijkstra(n);

    LL ans = INT_MAX;
    for(int u=1; u<=n; u++)
    {
        for(auto v : adj[u])
        {
            LL cur_cost = dist1[u] + dist2[v.to] + v.cost;
            if(cur_cost > dist1[n])
            {
                ans = min( ans,cur_cost );
            }
        }
    }

    cout<<"Case "<<casenum<<": "<<ans<<endl;

    clean(n);
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/not-the-best

Sol : We consider a path cost as this :
1) Cost from node 1 to node U
2) Cost from node U to node V
3) Cost from node V to node n
That's why make 2 dijkstra call from node 1 and node n.

*/