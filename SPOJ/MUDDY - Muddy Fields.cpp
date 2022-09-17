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
const int INF = 2000000000;

struct Edge{
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic{

  int N;
  vector<vector<Edge> > G;
  vector<Edge*> dad;
  vector<int> Q;

  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].emplace_back(from, to, cap, 0, G[to].size());
    if (from == to) G[from].back().index++;
    G[to].emplace_back(to, from, 0, 0, G[from].size() - 1);
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        if (!e) { amt = 0; break; }
        amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

int n, m;
char mat[N][N];
PII cells[N][N];

void solve(int casenum)
{

    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>mat[i][j];
        }
    }

    vector <int> b, w;
    int id = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(mat[i][j] == '*')
            {
                ++id;
                cells[i][j].first = id;
                w.PB(id);
                while(mat[i][j+1] == '*' and j <= m)
                {
                    j++;
                    cells[i][j].first = id;
                }
            }
        }
    }

    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {      
            if(mat[i][j] == '*')
            {
                ++id;
                cells[i][j].second = id;
                b.PB(id);
                while(mat[i+1][j] == '*' and i <= n)
                {
                    i++;
                    cells[i][j].second = id;
                }
            }
        }
    }

    Dinic d(id+2);
    int source = 0, sink = id+1;

    for(int x : w) d.AddEdge(source,x,1);
    for(int x : b) d.AddEdge(x,sink,1);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(mat[i][j] == '*')
            {
                d.AddEdge(cells[i][j].first,cells[i][j].second,1);
            }
        }
    }

    int ans = d.GetMaxFlow(source,sink);

    cout<<ans<<endl;
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

Link : https://www.spoj.com/problems/MUDDY/

Sol : It is a vertex cover problem. We have to select minimum number of vertex to cover all edges.
As we can take wooden board length as much as we can find muddy, then it is easy for us to make a bipartite graph. How?
When we find a muddy cell we will go as much adjacent muddy cell we find and place a wooden board.
By following this procedure, we will go through rows and columns and provide them an specific ID. Then for each muddy cell 
there will be a (X,Y). Then it is easy for us to make bipartite graph and calculate vertex cover.
    
*/