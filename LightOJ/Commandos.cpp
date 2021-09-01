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

const int N = 1005;
int n,m,startPlace,endPlace;
vector <int> adj[N];
set <int> nodes;
bool visited[N];
int dist[N];

void bfs(int s)
{
    visited[s] = true;
    dist[s] = 0;

    queue <int> q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front(); q.pop();

        For(i,0,sz(adj[u])-1)
        {
            int v = adj[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void clean()
{
    For(i,0,N-1) adj[i].clear();
    nodes.clear();
    mem(visited,false);
}


int main()
{
    int t;
    sfi(t);
    For(tt,1,t)
    {
        clean();

        sfi2(n,m);
        For(i,0,m-1)
        {
            int from, to;
            sfi2(from,to);
            adj[from].PB(to);
            adj[to].PB(from);
            nodes.insert(from);
            nodes.insert(to);
        }

        sfi2(startPlace,endPlace);

        int ans = 0;

        for(auto x : nodes)
        {
            mem(visited,false);
            bfs(x);
            ans = max(ans,(dist[startPlace]+dist[endPlace]));
        }


        printf("Case %d: %d\n", tt, ans);
    }

    //main();
}

/*

2
4
4
0 1
2 1
1 3
1 4
0 3
2
1
0 1
1 0

*/

