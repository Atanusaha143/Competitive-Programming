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

const int N = 1e6+10;
map <string, int> mp;
vector <int> adj[N], adj_rev[N], order;
int n,m;
bool visited[N];

void dfs1(int u)
{
    visited[u] = true;
    for(int v : adj[u])
        if(!(visited[v]))
            dfs1(v);
    order.PB(u);
}

void dfs2(int u)
{
    visited[u] = true;
    for(int v : adj_rev[u])
        if(!(visited[v]))
            dfs2(v);
}

void clean()
{
    For(i,0,N-1) adj[i].clear();
    For(i,0,N-1) adj_rev[i].clear();
    mem(visited,false);
    order.clear();
    mp.clear();
}

int main()
{
//    int t;
//    sfi(t);
//    For(tt,1,t) {}

    while(1)
    {
        sfi2(n,m);

        cin.ignore();

        if(n or m)
        {
            clean();

            int num = 0;
            For(i,1,n)
            {
                string str;
                getline(cin,str);

                string news = "";
                For(j,0,sz(str)-1)
                    if(str[j] != ' ' and str[j] != ',')
                        news += str[j];

                if(!mp[news]) mp[news] = ++num;
            }

            For(i,1,m)
            {
                string str;
                getline(cin,str);

                string news = "";
                For(j,0,sz(str)-1)
                    if(str[j] != ' ' and str[j] != ',')
                        news += str[j];

                string str1;
                getline(cin,str1);

                string news1 = "";
                For(j,0,sz(str1)-1)
                    if(str1[j] != ' ' and str1[j] != ',')
                        news1 += str1[j];

                adj[mp[news]].PB(mp[news1]);
                adj_rev[mp[news1]].PB(mp[news]);
            }

            For(i,1,num)
                if(!visited[i])
                    dfs1(i);

            mem(visited,false);
            reverse(all(order));
            int cnt = 0;
            For(i,0,sz(order)-1)
            {
                if(!(visited[order[i]]))
                {
                    cnt++;
                    dfs2(order[i]);
                }
            }

            printf("%d\n", cnt);
        }
        else break;
    }
}

/*

3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0


*/

