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
map <string,int> mp;
int indegree[N];

bool Kahn(int n)
{
    queue <int> q;
    for(int i=1; i<=n; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int u = q.front();
        ans.PB(u);
        q.pop();

        for(int v : adj[u])
        {
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }

    For(i,1,n)
        if(indegree[i])
            return true;
    return false;
}

void clean()
{
    For(i,0,N-1)
    {
        adj[i].clear();
        indegree[i] = 0;
    }

    ans.clear();
    mp.clear();
}

int main()
{
    int t;
    sfi(t);
    For(tt,1,t)
    {
        clean();

        int n;
        sfi(n);
        int num = 1;
        for(int i=0; i<n; i++)
        {
            string str1, str2;
            cin>>str1>>str2;
            if(!mp[str1]) mp[str1] = num++;
            if(!mp[str2]) mp[str2] = num++;
            adj[mp[str1]].PB(mp[str2]);
            indegree[mp[str2]]++;
        }

        bool ans = Kahn(sz(mp));

        if(ans) printf("Case %d: No\n", tt);
        else printf("Case %d: Yes\n", tt);
    }
    //main();
}

/*

*/

