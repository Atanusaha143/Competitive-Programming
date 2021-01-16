#include<bits/stdc++.h>
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

int dx[] = {0,1,0,-1}; // direction array
int dy[] = {-1,0,1,0};
int kx[] = {1,2,2,1,-1,-2,-2,-1}; // knights move
int ky[] = {2,1,-1,-2,-2,-1,1,2};

const int N = 250;
vector <int> adj[N];
vector <string> color(N);

bool bfs(int s)
{
    color[s] = "Red";
    queue <int> q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        For(i,0,sz(adj[u])-1)
        {
            int v = adj[u][i];
            if(color[v]=="White")
            {
                if(color[u]=="Red") color[v] = "Blue";
                else color[v] = "Red";
                q.push(v);
            }
            else if(color[v]==color[u]) return false;
        }
    }
    return true;
}

int main()
{
//    int t; sfi(t); For(tt,1,t){

    while(1)
    {
        int q;
        sfi(q);
        if(q==0) break;

        For(i,0,N-1) adj[i].clear();
        color.assign(N,"White");

        int n;
        sfi(n);
        For(i,0,n-1)
        {
            int from, to;
            sfi2(from,to);
            adj[from].PB(to);
            adj[to].PB(from);
        }

        bool ans = bfs(0);

        if(ans) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }

//    }

//    main();
}


