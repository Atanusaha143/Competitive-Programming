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

int dx[] = {0,1,0,-1}; // x axis
int dy[] = {-1,0,1,0}; // y axis

const LL N = 2e6+10;
bool visited[N];
vector <LL> adj[N];
LL level[N],visitedBy[N];

bool bfs(LL city, LL power, LL person)
{
    level[city] = 0;
    visited[city] = true;
    visitedBy[city] = person;

    queue <LL> q;
    q.push(city);

    while(!q.empty())
    {
        LL u = q.front();
        q.pop();

        for(LL i=0; i<LL(sz(adj[u])); i++)
        {
            LL v = adj[u][i];

            if(level[u]+1 <= power)
            {
                if(visited[v]==false)
                {
                    visited[v] = true;
                    visitedBy[v] = person;
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
            else if(level[u]+1 > power) break;
            else if(visitedBy[v]!=person) return false;
        }
    }

    return true;
}

int main()
{

    int t; sfi(t); For(tt,1,t){

        mem(visited,false);
        mem(adj,0);
        mem(level,0);
        mem(visitedBy,0);

        LL n,r,m;
        sfl3(n,r,m);
        for(LL i=1; i<=r; i++)
        {
            LL from, to;
            sfl2(from,to);
            adj[from].PB(to);
            adj[to].PB(from);
        }

        map <LL,LL> mp;
        for(LL i=1; i<=m; i++)
        {
            LL city, power;
            sfl2(city,power);
            mp[city] = power;
        }

        bool check = true;
        LL i = 1;
        for(auto x : mp)
        {
            if(visited[x.fi]==false)
            {
                check = bfs(x.fi,x.se,i++);
                if(check==false) break;
            }
            else
            {
                check = false;
                break;
            }
        }

        For(i,1,n)
        if(visited[i]==false)
        { check = false; break; }

        if(check==false) printf("No\n");
        else printf("Yes\n");
    }

//    main();
}

