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

const int N = 205;
char mat[N][N];
int n,m,start,finish;
bool visited1[N][N], visited2[N][N];
int dist1[N][N], dist2[N][N];
queue <PII> q;

void clean()
{
    while(!q.empty()) q.pop();
    mem(visited1,false);
    mem(visited2,false);
    mem(dist1,0);
    mem(dist2,0);
}

bool check1(int startX, int startY)
{
    return (startX >= 0 and
            startX < n and
            startY >= 0 and
            startY < m and
            !visited1[startX][startY] and
            mat[startX][startY] == '.');
}

bool check2(int startX, int startY)
{
    return (startX >= 0 and
            startX < n and
            startY >= 0 and
            startY < m and
            !visited2[startX][startY] and
            (mat[startX][startY] == '.' or mat[startX][startY] == 'F'));
}

void bfs1(int startX, int startY)
{
    visited1[startX][startY] = true;
    dist1[startX][startY] = 0;

    queue <PII> q;
    q.push({startX,startY});

    while(!q.empty())
    {
        PII curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        For(i,0,3)
        {
            int newX = x + d4x[i];
            int newY = y + d4y[i];

            if(check1(newX,newY))
            {
                visited1[newX][newY] = true;
                dist1[newX][newY] = dist1[x][y] + 1;
                q.push({newX,newY});
            }
        }
    }
}

int bfs2()
{
    while(!q.empty())
    {
        PII curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        For(i,0,3)
        {
            int newX = x + d4x[i];
            int newY = y + d4y[i];

            if(check2(newX,newY))
            {
                visited2[newX][newY] = true;
                dist2[newX][newY] = dist2[x][y] + 1;
                q.push({newX,newY});
            }
        }
    }
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
        {
            For(j,0,m-1)
            {
                cin>>mat[i][j];
                if(mat[i][j] == 'J')
                {
                    start = i;
                    finish = j;
                }
                else if(mat[i][j] == 'F')
                {
                    q.push({i,j});
                }
            }
        }

        bool ans = false;
        For(i,0,3)
        {
            int newx = start + d4x[i];
            int newy = finish + d4x[i];
            if(newx < 0 or newx >= n or newy < 0 or newy >= m)
            {
                ans = true;
                break;
            }
        }

        if(ans)
        {
            printf("Case %d: 1\n", tt);
        }
        else
        {
            bfs1(start,finish);
            bfs2();

            int ans = PINF;
            bool flag = false;
            For(i,0,n-1)
            {
                For(j,0,m-1)
                {
                    if(mat[i][j] == '.' and visited1[i][j])
                    {
                        For(k,0,3)
                        {
                            int newx = i + d4x[k];
                            int newy = j + d4x[k];
                            if(newx < 0 or newx >= n or newy < 0 or newy >= m)
                            {
                                if(dist1[i][j] < dist2[i][j])
                                {
                                    ans = min(ans, dist1[i][j] + 1);
                                }
                            }
                        }
                    }
                }
            }

            if(ans != PINF) printf("Case %d: %d\n", tt, ans);
            else printf("Case %d: IMPOSSIBLE\n",tt);
        }
    }
    //main();
}

/*

2
4 5
##.##
#.F.#
#.J.#
#...#
3 3
###
#J.
#.F


*/

