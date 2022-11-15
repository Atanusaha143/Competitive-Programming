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

int n,m,k,d;
LL dist[15][N];

struct Node
{
    int node_num, node_cost, cnt;
    Node(int node_num, int node_cost, int cnt)
    {
        this->node_num=node_num;
        this->node_cost=node_cost;
        this->cnt=cnt;
    }
};
struct Edge
{
    int v,w,type;
    Edge(int v, int w, int type)
    {
        this->v=v;
        this->w=w;
        this->type=type;
    }
};
bool operator<(Node a, Node b)
{
    return a.node_cost>b.node_cost;
}
vector<Edge>adj[N];

void dijkstra(int s)
{
    For(i,0,d)
    {
        For(j,0,n)
        {
            dist[i][j]=1e12;
        }
    }
    dist[0][s]=0;

    priority_queue<Node>pq;
    pq.push(Node(s,0,0));

    while (!pq.empty())
    {
        Node u=pq.top(); pq.pop();
        int unode=u.node_num;
        int ucost=u.node_cost;
        int ud=u.cnt;
        if(ucost>dist[ud][unode]) continue;
        for(Edge v:adj[unode])
        {
            int vnode=v.v;
            int vcost=v.w;
            int cur_d=ud+v.type;
            LL newDistance=ucost+vcost;
            if(cur_d<=d and newDistance<dist[cur_d][vnode])
            {
                dist[cur_d][vnode]=newDistance;
                pq.push(Node(vnode,newDistance,cur_d));
            }
        }
    }
}


void solve(int casenum)
{

    cin>>n>>m>>k>>d;

    For(i,0,n)if(sz(adj[i]))adj[i].clear();

    int u,v,w;
    For(i,1,m)
    {
        cin>>u>>v>>w;
        adj[u].PB(Edge(v,w,0));
    }
    For(i,1,k)
    {
        cin>>u>>v>>w;
        adj[u].PB(Edge(v,w,1));
    }
    dijkstra(0);
    cout<<"Case "<<casenum<<": ";
    LL ans=1e12;
    For(i,0,d)
    {
        ans=min(ans,dist[i][n-1]);
    }
    if(ans==1e12) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
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

Link : https://lightoj.com/problem/new-traffic-system

Sol: For each node we will calculate, to reach a node using x(<=d) new edges what is the
minimum cost. For each x(<=d) we will get an answer and minimum of them is the answer.


*/
