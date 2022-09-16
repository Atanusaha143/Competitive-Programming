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

const int N = 100 + 10;
const int MOD = 1000000007;

/// MCMF
typedef long long T1;//for cost
typedef long long T2;//for flow
const int maxn = 20100;
const T1 INF = 1e12;
const T2 inf = 1e12;
const T1 eps = 0;
struct Edge {
    int from, to;
    T2 cap, flow;
    T1 cost;
};
struct MCMF {//0-indexed
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int p[maxn],inq[maxn];
    T1 d[maxn];
    T2 a[maxn];
    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,T2 cap,T1 cost) {
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    pair<T1,T2> Mincost(int s,int t) {//bellmanFord
        T1 tot_cost = 0;
        T2 tot_flow = 0;
        while(true) {
            for(int i = 0; i < n; i++) d[i] = INF;
            d[s] = 0;
            p[s] = 0;
            a[s] = inf;
            bool up=true;
            while(up) {
                up=false;
                for(int u = 0; u < n; u++) {
                    if(d[u]-INF>=-eps)continue;
                    for(int j:G[u]) {
                        Edge &e=edges[j];
                        if(e.cap > e.flow && d[e.to] > d[u] + e.cost+eps) {
                            d[e.to] = d[u] + e.cost;
                            p[e.to] = j;
                            a[e.to] = min(a[u], e.cap - e.flow);
                            up=true;
                        }
                    }
                }
            }
            if(abs(d[t]-INF)<=eps)break;
            tot_cost += (T1)d[t] * a[t];
            tot_flow += (T2)a[t];
            int u = t;
            while(u != s) {
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
                u = edges[p[u]].from;
            }
        }
        return {tot_cost,tot_flow};
    }
    pair<T1,T2> Mincost2(int s,int t) {//SPFA
        T1 tot_cost = 0;
        T2 tot_flow = 0;
        while(true) {
            for(int i = 0; i < n; i++) d[i] = INF;
            memset(inq, 0, sizeof(inq));
            d[s] = 0;
            inq[s] = 1;
            p[s] = 0;
            a[s] = inf;
            queue<int> Q;
            srand(time(NULL));
            Q.push(s);
            while(!Q.empty()) {
                int u = Q.front();
                Q.pop();
                inq[u] = 0;
                for(int i = 0; i < G[u].size(); i++) {
                    Edge& e = edges[G[u][i]];
                    if(e.cap > e.flow && d[e.to] > d[u] + e.cost+eps) {
                        d[e.to] = d[u] + e.cost;
                        p[e.to] = G[u][i];
                        a[e.to] = min(a[u], e.cap - e.flow);
                        if(!inq[e.to]) {
                            Q.push(e.to);
                            inq[e.to] = 1;
                        }
                    }
                }
            }
            if(abs(d[t]-INF)<=eps)break;
            tot_cost += (T1)d[t] * a[t];
            tot_flow += a[t];
            int u = t;
            while(u != s) {
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
                u = edges[p[u]].from;
            }
        }
        return {tot_cost,tot_flow};
    }
} mcmf;

LL n, m, cost[N][N];

int rightdown_x[2] = {0,1};
int rightdown_y[2] = {1,0};

void solve(int casenum)
{

    cin>>n>>m;
    map <PII,int> compress;
    int total = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>cost[i][j];
            compress[{i,j}] = ++total;
        }
    }

    mcmf.init((2*total)+5);

    int source = 0, sink = (2*total)+1;
    mcmf.AddEdge(source,1,2,0);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int id1 = compress[{i,j}];
            int w = -cost[i][j];
            int v = id1 + total;
            if(i == 1 and j == 1)
            {
                mcmf.AddEdge(id1,v,2,0);
            }
            else if(i == n and j == m)
            {
                mcmf.AddEdge(id1,v,2,0);
            }
            else
            {
                mcmf.AddEdge(id1,v,1,0);
            }
            for(int k=0; k<2; k++)
            {
                int newx = i + rightdown_x[k];
                int newy = j + rightdown_y[k];
                if(newx <= n and newy <= m)
                {
                    int id2 = compress[{newx,newy}];
                    mcmf.AddEdge(v,id2,1,w);
                }
            }
        }
    }
    mcmf.AddEdge(total,sink,2,0);
    PLL ans = mcmf.Mincost2(source,sink);
    LL res = -1 * ans.first - cost[1][1] + cost[n][m];
    cout<<"Case "<<casenum<<": "<<res<<endl;
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

Link : https://lightoj.com/problem/baker-vai
Sol : Give edge from every possible direction with flow 1 because we need unique path and cost negative to get the max cost.
Remember to split 1st node and last noded with flow 2. For that 1st node's cost will be added twice and last node's cost won't.
So, we have to subtract 1st node's cost and add last node's cost.

*/

