#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define PINF            INT_MAX
#define NINF            INT_MIN
#define sz(x)           x.size()
#define PB              push_back
#define MP              make_pair
#define asort(x)        sort(all(x));
#define PI              (2.0*acos(0.0))
#define all(x)          x.begin(),x.end()
#define now             cerr<<"Here"<<endl;
#define For(i, j, k)    for(int i = j; i <= k; i++)
#define Rof(i, j, k)    for(int i = j; i >= k; i--)
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
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

///---------------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------------

const int N = 1e4 + 10;
const int MOD = 1000000007;

int n,m,src,dest,k;
LL dist1[N], dist2[N];

struct Node
{
    LL node_num, node_cost;
    Node(int node_num, int node_cost)
    {
        this->node_num=node_num;
        this->node_cost=node_cost;
    }
};
struct Edge
{
    LL v,w;
    Edge(int v, int w)
    {
        this->v=v;
        this->w=w;
    }
};
bool operator<(Node a, Node b)
{
    return a.node_cost>b.node_cost;
}

vector<Edge>adj[N],adj_rev[N];

void dijkstra1(int s)
{
    For(i,1,n)dist1[i]=1e12;
    dist1[s]=0;

    priority_queue<Node>pq;
    pq.push(Node(s,0));

    while (!pq.empty())
    {
        Node u=pq.top(); pq.pop();
        int unode=u.node_num;
        LL ucost=u.node_cost;

        if(ucost>dist1[unode]) continue;

        for(Edge v:adj[unode])
        {
            int vnode=v.v;
            LL vcost=v.w;
            LL newDistance=ucost+vcost;
            if(newDistance<dist1[vnode])
            {
                dist1[vnode]=newDistance;
                pq.push(Node(vnode,newDistance));
            }
        }
    }
}
void dijkstra2(int s)
{
    For(i,1,n)dist2[i]=1e12;
    dist2[s]=0;

    priority_queue<Node>pq;
    pq.push(Node(s,0));
    while (!pq.empty())
    {
        Node u=pq.top(); pq.pop();
        int unode=u.node_num;
        LL ucost=u.node_cost;

        if(ucost>dist2[unode]) continue;

        for(Edge v:adj_rev[unode])
        {
            int vnode=v.v;
            LL vcost=v.w;
            LL newDistance=ucost+vcost;
            if(newDistance<dist2[vnode])
            {
                dist2[vnode]=newDistance;
                pq.push(Node(vnode,newDistance));
            }
        }
    }
}

struct info
{
    LL u,v,w;
};

void solve(int casenum)
{
    cin>>n>>m>>src>>dest>>k;
    For(i,1,n)
    {
        if(sz(adj[i]))adj[i].clear();
        if(sz(adj_rev[i]))adj_rev[i].clear();
    }

    LL u,v,w;
    vector<info>vec;
    For(i,1,m)
    {
        cin>>u>>v>>w;
        adj[u].PB(Edge(v,w));
        adj_rev[v].PB(Edge(u,w));
        vec.PB({u,v,w});
    }

    LL ans=-1;

    dijkstra1(src);
    dijkstra2(dest);

    For(i,0,sz(vec)-1)
    {
        int u=vec[i].u;
        int v=vec[i].v;
        LL w=vec[i].w;
        if(dist1[u]==1e12 or dist2[v]==1e12)continue;
        LL sum=dist1[u]+w+dist2[v];
        if(sum<=k)
        {
            ans=max(ans,w);
        }
    }
    cout<<"Case "<<casenum<<": "<<ans<<endl;
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

Link: https://lightoj.com/problem/toll-management
Sol: As we need to output an edge cost which satisfies the constraints, we took every edge and validate it.
One dijkstra from source and another one from destination.
Let's say we took an edge denoting u,v;
So a shortest path from source to destination consisting that edge will be:
cost to go from source to u + cost to go from destination to v + that edge cost.
If this path cost satisfies our constraints then we will mark this one as an answer and from all these
path whose satisfies our constraints, we need the maximum one.

*/
