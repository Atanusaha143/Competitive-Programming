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

const int N = 2e5 + 10;
//const LL MOD = 1000000007;
vector <LL> adj[N];
LL startTime[N], finishTime[N], traverse[N], cost[N], currTime;
LL tree[4*N];
bool visited[N];

void euler(LL s)
{
    if(visited[s]) return;
    visited[s] = true;
    startTime[s] = currTime;
    traverse[currTime] = s;
    currTime++;

    for(int v : adj[s])
        if(!visited[v])
            euler(v);

    finishTime[s] = currTime - 1;
}

void build(LL node, LL b, LL e)
{
    if(b==e)
    {
        tree[node] = cost[traverse[e]];
        return;
    }

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    build(left,b,mid);
    build(right,mid+1,e);
    tree[node] = tree[left] + tree[right];
}

void update(LL node, LL b, LL e, LL i, LL value)
{
    if(b > i or e < i) return;
    if(b == e and b == i)
    {
        tree[node] = value;
        return;
    }

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    if(mid >= i) update(left,b,mid,i,value);
    else update(right,mid+1,e,i,value);

    tree[node] = tree[left] + tree[right];
}

LL query(LL node, LL b, LL e, LL i, LL j)
{
    if(b > j or e < i) return 0;
    if(b >= i and e <= j) return tree[node];

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    LL p = query(left,b,mid,i,j);
    LL q = query(right,mid+1,e,i,j);

    return (LL)(p + q);
}

int main()
{
//    int t; sfi(t); For(tt,1,t){}

      LL n,q;
      sfl2(n,q);

      For(i,1,n)
      {
          adj[i].clear();
          visited[i] = false;
          startTime[i] = 0;
          finishTime[i] = 0;
          traverse[i] = 0;
          cost[i] = 0;
          currTime = 1;
      }

      For(i,1,n) sfl(cost[i]);
      For(i,1,n-1)
      {
          LL from, to;
          sfl2(from, to);
          adj[from].PB(to);
      }

      euler(1LL);
      build(1LL,1LL,n);

      while(q--)
      {
          LL k;
          sfl(k);

          if(k == 1)
          {
             LL node, value;
             sfl2(node,value);
             update(1LL,1LL,n,startTime[node],value);
          }
          else
          {
            LL node;
            sfl(node);
            LL ans = query(1LL,1LL,n,startTime[node], finishTime[node]);
            printf("%lld\n", ans);
          }
      }

//      for(int i=1; i<=n; i++) cout<<startTime[i]<<" ";
//      cout<<NL;
//      for(int i=1; i<=n; i++) cout<<finishTime[i]<<" ";
//      cout<<NL;
//      for(int i=1; i<=n; i++) cout<<traverse[i]<<" ";

//    main();
}

/*

5 4
4 2 5 2 1
1 2
1 3
2 4
2 5
2 2
1 2 7
2 2
2 1

*/


