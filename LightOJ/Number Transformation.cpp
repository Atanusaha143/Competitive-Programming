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
int cost[N];
bool visited[N];
//const LL MOD = 1000000007;
vector <int> primeFact[N];

void primeFactor(int n)
{
    int nn = n;
    set <int> st;
    bool flag = false;
    while(n%2==0)
    {
        if(!flag)
        {
            st.insert(2);
            flag = true;
        }
        n /= 2;
    }

    for(int i=3; i*i<=n; i+=2)
    {
        flag = false;
        while(n%i==0)
        {
            if(!flag)
            {
                st.insert(i);
                flag = true;
            }
            n /= i;
        }
    }

    if(n>2) st.insert(n);

    for(int x : st)
        if(x != nn)
            primeFact[nn].PB(x);
}

int bfs(int s, int t)
{
    visited[s] = true;
    queue <int> q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v : primeFact[u])
        {
            int curr = u + v;
            if(curr <= t and !visited[curr])
            {
                visited[curr] = true;
                int currCost = cost[u] + 1;
                cost[curr] = currCost;
                q.push(curr);
                if(curr == t) return currCost;
            }
        }
    }
    return -1;
}

void clean()
{
    mem(visited,false);
    mem(cost,0);
}

int main()
{
    for(int i=2; i<=1010; i++)
        primeFactor(i);

    int t; sfi(t); For(tt,1,t) {

            clean();

            int source, target;
            sfi2(source,target);
            if(source == target) printf("Case %d: 0\n",tt);
            else
            {
                int ans = bfs(source, target);
                printf("Case %d: %d\n", tt, ans);
            }
    }
}

/*

*/


