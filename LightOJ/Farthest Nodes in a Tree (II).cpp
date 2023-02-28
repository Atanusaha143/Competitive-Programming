#include <bits/stdc++.h>
using namespace std;

#define NL              '\n'
#define PINF            INT_MAX
#define NINF            INT_MIN
#define sz(x)           x.size()
#define PB              push_back
#define MP              make_pair
#define asort(x)        sort(all(x));
#define PI              (2.0*acos(0.0))
#define all(x)          x.begin(),x.end()
#define Now             cerr<<"Here"<<endl;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL  my_rand(LL l, LL r) { return uniform_int_distribution<LL>(l, r) (rng); }

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

const int N = 3e4 + 10;
const int MOD = 1000000007;

int n;
vector<PII>adj[N];
bool visited[N];
int dist[N],dist1[N],dist2[N];

int BFS1(int u)
{
    visited[u]=true;
    dist[u]=0;
    int maxcost=0,nodenum=0;
    queue<int>q;
    q.push(u);
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for(PII v:adj[u])
        {
            int vnode=v.first;
            int vcost=v.second;
            if(!visited[vnode])
            {
                visited[vnode]=true;
                dist[vnode]=dist[u]+vcost;
                q.push(vnode);
                if(dist[vnode]>maxcost)
                {
                    maxcost=dist[vnode];
                    nodenum=vnode;
                }
            }
        }
    }
    return nodenum;
}
int BFS2(int u)
{
    visited[u]=true;
    dist1[u]=0;
    int maxcost=0,nodenum=0;
    queue<int>q;
    q.push(u);
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for(PII v:adj[u])
        {
            int vnode=v.first;
            int vcost=v.second;
            if(!visited[vnode])
            {
                visited[vnode]=true;
                dist1[vnode]=dist1[u]+vcost;
                q.push(vnode);
                if(dist1[vnode]>maxcost)
                {
                    maxcost=dist1[vnode];
                    nodenum=vnode;
                }
            }
        }
    }
    return nodenum;
}
void BFS3(int u)
{
    visited[u]=true;
    dist2[u]=0;
    queue<int>q;
    q.push(u);
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for(PII v:adj[u])
        {
            int vnode=v.first;
            int vcost=v.second;
            if(!visited[vnode])
            {
                visited[vnode]=true;
                dist2[vnode]=dist2[u]+vcost;
                q.push(vnode);
            }
        }
    }
}

void clean(int n)
{
    For(i,0,n-1)
    {
        if(sz(adj[i])) adj[i].clear();
        dist[i]=dist1[i]=dist2[i]=0;
        visited[i]=false;
    }
}
void solve(int casenum)
{
    cin>>n;
    clean(n);

    int u,v,w;
    For(i,1,n-1)
    {
        cin>>u>>v>>w;
        adj[u].PB({v,w});
        adj[v].PB({u,w});
    }
    int p=BFS1(0);
    mem(visited,false);
    int q=BFS2(p);
    mem(visited,false);
    BFS3(q);

    cout<<"Case "<<casenum<<":"<<NL;
    For(i,0,n-1)
    {
        LL curans=max(dist1[i],dist2[i]);
        cout<<curans<<NL;
    } 
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
https://lightoj.com/problem/farthest-nodes-in-a-tree-ii

Sol : Get the farthest node from any node. Let's say it is p.
Then run BFS from node p and get the farthest node again. Let's say it is q.
Also save distances from node p to any node.
Again run BFS from node q and save distances from node q to any node.
Now, we know two farthest node and distances from these node to anynode i.
Then we can say that the farthest node of i will be the one who will give us
maximum distance from (p to i) or (q to i).


*/