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

const int N = 500 + 10;
const int MOD = 1000000007;

int n, m, k;
int dist[N];

struct Node
{
    int node_num, node_cost;
    Node(int node_num, int node_cost)
    {
        this->node_num=node_num;
        this->node_cost=node_cost;
    }
};
struct Edge
{
    int v,w;
    Edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};
bool operator<(Node a, Node b)
{
    return a.node_cost>b.node_cost;
}

vector<Edge>adj[N];

void dijkstra(int s)
{
    For(i,0,n-1)dist[i]=1e5;

    priority_queue<Node>pq;
    pq.push(Node(s,0));
    dist[s]=0;
    while (!pq.empty())
    {
        Node u=pq.top(); pq.pop();
        int unode=u.node_num;
        int ucost=u.node_cost;
        if(ucost>dist[unode]) continue;
        for(Edge v:adj[unode])
        {
            int vnode=v.v;
            int vcost=v.w;
            int cur_max=max(ucost,vcost);
            if(cur_max<dist[vnode])
            {
                dist[vnode]=cur_max;
                pq.push(Node(vnode,cur_max));
            }
        }
    }
}

void clean()
{
    For(i,0,n-1)
    {
        if(adj[i].size())
        {
            adj[i].clear();
        }
    }
}


void solve(int casenum)
{
    cin>>n>>m;
    int u, v, w;
    For(i,1,m)
    {
        cin>>u>>v>>w;
        adj[u].PB(Edge(v,w));
        adj[v].PB(Edge(u,w));
    }
    cin>>k;
    dijkstra(k);
    cout<<"Case "<<casenum<<":"<<endl;
    For(i,0,n-1)
    {
        if(dist[i]==1e5) cout<<"Impossible"<<endl;
        else cout<<dist[i]<<endl;
    }

    clean();
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

Link : https://lightoj.com/problem/country-roads

Sol : As we need the minimum among the maximum edge cost for all possible path to
reach a node U, we can only update a node cost when we get a better node cost.
Let's consider MX as the current answer from source to node U and if we want
to go node V from U then it have to be a better one. This means max(MX,vNode_cost)
have to be less than previously calculated cost for node V.

*/
