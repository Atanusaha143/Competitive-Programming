#include <bits/stdc++.h>
using namespace std;

#define NL              '\n'
#define sz(x)           x.size()
#define PINF            INT_MAX
#define NINF            INT_MIN
#define PI              (2.0*acos(0.0))

#define sfi(x)          scanf("%d",&x)
#define sfi2(x,y)       scanf("%d %d",&x,&y)
#define sfi3(x,y,z)     scanf("%d %d %d",&x,&y,&z)
#define sfl(x)          scanf("%lld",&x)
#define sfl2(x,y)       scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z)     scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x)          scanf("%lf",&x);
#define sfd2(x,y)       scanf("%lf %lf",&x,&y);

#define max3(a,b,c)     max(a,max(b,c))
#define max4(a,b,c,d)   max(max3(a,b,c),d)
#define min3(a,b,c)     min(a,min(b,c))
#define min4(a,b,c,d)   min(a,min3(b,c,d))

#define PB              push_back
#define MP              make_pair
#define For(i, j, k)    for(int i = j; i <= k; i++)
#define Rof(i, j, k)    for(int i = j; i >= k; i--)
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define now             cout<<"Here"<<NL;

#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define READ            freopen("input.txt","r",stdin)
#define WRITE           freopen("output.txt","w",stdout)
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

LL gcd(LL a,LL b) { return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a,LL b) { return (a/gcd(a,b))*b; }

LL power_mod(LL base, LL power, LL mod)
{
    if(power==0) return 1LL;
    else if(power%2LL == 1)
    {
        LL p1 = base % mod;
        LL p2 = (power_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2LL == 0)
    {
        LL p1 = (power_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}

// Grid direction array [4]
int X[4]= {0,0,-1,1};
int Y[4]= {1,-1,0,0};
// Grid direction array [8]
int X8[8]= {0,0,1,-1,-1,1,1,-1};
int Y8[8]= {1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

inline bool checkBit(int N, int pos){return (bool)(N & (1 << pos));}
inline int setBit(int N, int pos) { return N = N | (1 << pos); }

const int N = 1e4 + 10;
int arr[N], n, m;
bool visited[N];
vector <int> adj[N], currAns;
//const LL MOD = 1000000007;

void bfs(int s)
{
    currAns.PB(s);

    visited[s] = true;
    queue <int> q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v : adj[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
                currAns.PB(v);
            }
        }
    }
}

void clean()
{
    for(int i=0; i<N; i++)
    {
        adj[i].clear();
        visited[i] = false;
        currAns.clear();
    }
}

int main()
{
    int t; sfi(t); For(tt,1,t) {

        clean();

        sfi2(n,m);

        int total = 0;
        for(int i=1; i<=n; i++)
        {
            sfi(arr[i]);
            total += arr[i];
        }

        for(int i=1; i<=m; i++)
        {
            int u, v;
            sfi2(u,v);
            adj[u].PB(v);
            adj[v].PB(u);
        }

        printf("Case %d: ", tt);
        if(total % n) printf("No\n");
        else
        {
            bool flag = false;
            vector <int> ans;
            for(int i=1; i<=n; i++)
            {
                if(!visited[i])
                {
                    currAns.clear();
                    bfs(i);
                    int sum = 0;
                    for(auto x : currAns) sum += arr[x];
                    if(sum % (int)currAns.size())
                    {
                        flag = true;
                        break;
                    }
                    else
                    {
                        int divi = sum/currAns.size();
                        ans.PB(divi);
                    }
                }
            }

            if(!flag)
            {
                set <int> st;
                for(auto x : ans)
                    st.insert(x);

                if(st.size() == 1) printf("Yes\n");
                else printf("No\n");
            }
            else printf("No\n");
        }

    }
}

/*

1
6 4
1 0 2 1 0 2
1 2
2 3
4 5
5 6

*/


