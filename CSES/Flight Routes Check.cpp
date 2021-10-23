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

// Grid direction array [4]
int X[4]= {0,0,-1,1};
int Y[4]= {1,-1,0,0};
// Grid direction array [8]
int X8[8]= {0,0,1,-1,-1,1,1,-1};
int Y8[8]= {1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

const int N = 2e5+10;
vector <int> adj[N], adj_rev[N], order, ele;
bool visited[N];
int n,m;

void getOrder(int u)
{
    visited[u] = true;
    for(int v : adj[u])
        if(!(visited[v]))
            getOrder(v);
    order.PB(u);
}

void dfs(int u)
{
    visited[u] = true;
    ele.PB(u);
    for(int v : adj_rev[u])
        if(!(visited[v]))
            dfs(v);
}

int main()
{

    //main();
    sfi2(n,m);
    For(i,1,m)
    {
        int u,v;
        sfi2(u,v);
        adj[u].PB(v);
        adj_rev[v].PB(u);
    }

    For(i,1,n)
    if(!(visited[i]))
        getOrder(i);

    reverse(all(order));
    mem(visited,false);

    vector <vector<int>> allEle;
    for(int x : order)
    {
        if(!visited[x])
        {
            dfs(x);
            allEle.PB(ele);
            ele.clear();
        }
    }

    if(sz(allEle) == 1) printf("YES");
    else
    {
        printf("NO\n");
        int u = 0, v = 0;
        for(int i=0; i<sz(allEle); i++)
        {
            if(u and v) break;
            vector <int> vec = allEle[i];
            asort(vec);
            if(!u) u = vec[sz(vec)-1];
            else if(!v) v = vec[0];
        }

        printf("%d %d", v, u);
    }
}

/*

4 5
1 2
2 3
3 1
1 4
3 4

*/

