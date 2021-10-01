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

int d4x[] = {0,1,0,-1}; // 4 direction array
int d4y[] = {-1,0,1,0};
int d8x[] = {0,1,0,-1,1,-1,1,-1}; // 8 direction array
int d8y[] = {1,0,-1,0,1,-1,-1,1};
int kx[] = {1,2,2,1,-1,-2,-2,-1}; // knights move
int ky[] = {2,1,-1,-2,-2,-1,1,2};

const int N = 505;
int mat[N][N];
int dist[N][N];
bool visited[N][N];
int n,m,maxi;
queue <PII> q;

void clean()
{
    maxi = 0;
    while(!q.empty()) q.pop();
    mem(visited,false);
    mem(dist,0);
}

bool check(int newX, int newY)
{
    return (newX >= 0 and newX < n and newY >=0 and newY <m and !visited[newX][newY]);
}

int bfs()
{
    while(!q.empty())
    {
        PII curr = q.front();
        q.pop();

        For(i,0,7)
        {
            int newX = d8x[i] + curr.first;
            int newY = d8y[i] + curr.second;

            if(check(newX,newY))
            {
                visited[newX][newY] = true;
                dist[newX][newY] = dist[curr.first][curr.second] + 1;
                q.push({newX,newY});
            }
        }
    }

    int maxi = -1;
    For(i,0,n-1)
    For(j,0,m-1)
    maxi = max(maxi,dist[i][j]);

    return maxi;
}

int main()
{
    int t;
    sfi(t);
    For(tt,1,t)
    {
        clean();

        sfi2(n,m);
        For(i,0,n-1)
        For(j,0,m-1)
        {
            sfi(mat[i][j]);
            maxi = max(maxi,mat[i][j]);
        }

        For(i,0,n-1)
        For(j,0,m-1)
        {
            if(mat[i][j] == maxi)
            {
                q.push({i,j});
                visited[i][j] = true;
            }
        }

        printf("%d\n", bfs());
    }

    //main();
}

/*


*/
