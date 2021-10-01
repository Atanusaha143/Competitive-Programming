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

const int N = 1e4+10;
vector <int> adj[N], ans;
int indegree[N];
bool cycle;

void Kahn(int n)
{
    priority_queue<int, vector<int>, greater<int> > q;
    For(i,1,n)
        if(indegree[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int u = q.top();
        ans.PB(u);
        q.pop();

        for(int v : adj[u])
        {
            indegree[v]--;
            if(indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    bool flag = false;
    For(i,1,n)
    if(indegree[i])
    {
        flag = true;
        break;
    }

    if(flag) printf("Sandro fails.");
    else
    {
        For(i,0,sz(ans)-1)
        {
            printf("%d", ans[i]);
            if(i!=sz(ans)-1) printf(" ");
        }
    }
}
int main()
{
    int n,m;
    sfi2(n,m);
    For(i,1,m)
    {
        int from, to;
        sfi2(from,to);
        adj[from].PB(to);
        indegree[to]++;
    }

    Kahn(n);

    //main();
}

/*

8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6

*/

