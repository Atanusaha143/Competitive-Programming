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
bool compare(string &str1, string &str2) { return str1.size() > str2.size(); }

// Grid direction array [4]
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
// Grid direction array [8]
int X8[8]={0,0,1,-1,-1,1,1,-1};
int Y8[8]={1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

const LL N = 1e5+10;
vector <LL> adj[N];
bool visited[N];
LL color[N], black[N], white[N];

void dfs(int s)
{
    visited[s] = true;

    for(int i=0; i<sz(adj[s]); i++)
    {
        LL v = adj[s][i];
        if(!visited[v])
        {
            dfs(v);
            white[s] += white[v];
            black[s] += black[v];
        }
    }
}
int main()
{
    int nodes;
    sfi(nodes);
    for(int i=0; i<nodes; i++)
    {
        sfl(color[i]);
        if(color[i] == 1) white[i] = 1;
        else black[i] = 1;
    }
    for(int i=0; i<nodes-1; i++)
    {
        int from, to;
        sfi2(from,to);
        adj[from].PB(to);
        adj[to].PB(from);
    }

    dfs(0);

    LL initWhite = white[0];

    LL ans = 0;
    for(int i=0; i<nodes; i++)
    {
        LL currWhite = white[i];
        LL currBlack = black[i];
        LL currAns = (initWhite - currWhite) + currBlack;
        ans = max(ans,currAns);
    }
    printf("%lld\n", ans);
    //main();
}

/*

10
0 1 0 0 1 1 0 1 0 0
0 4
0 1
1 7
0 5
5 8
8 6
1 9
8 2
6 3

9
1 1 1 1 1 1 1 1 0
0 1
0 2
1 3
1 4
2 5
2 6
4 7
4 8

9
0 1 1 1 1 1 1 1 1
0 1
0 2
1 3
1 4
2 5
2 6
4 7
4 8

1
1

*/

