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

const int N = 1e3;
bool visited[N][N];
int level[N][N];
int totalRow,totalCol;

// checking if Forward, Backward, Upward and Downward is able to go
bool check(int newX, int newY)
{
    if(newX >=0 and newY >=0 and  newX < totalRow
       and newY <totalCol and visited[newX][newY]==false)
        return true;
    else return false;
}

// If you are to beat your guard, you’d have to find his fastest route long before he finds it = BFS
void bfs(int initialX, int initialY)
{
    visited[initialX][initialY] = true;

    queue <PII> q; // for handling row and column
    q.push({initialX,initialY});

    while(!q.empty())
    {
        PII curr = q.front(); // curr can keep the front row and column
        q.pop();

        For(i,0,3)
        {
            // new index to go
            int newX = curr.fi + dx[i];
            int newY = curr.se + dy[i];

            // checking the ability
            if(check(newX,newY))
            {
                q.push({newX,newY});
                visited[newX][newY] = true;
                level[newX][newY] = level[curr.fi][curr.se] + 1;
            }
        }
    }
}
int main()
{

    // for several test cases
    while(1)
    {
        mem(visited,false);
        mem(level,0);

        sfi2(totalRow,totalCol);
        if(totalRow==0 and totalCol==0) break;
        int q;
        sfi(q);
        while(q--)
        {
            int rowNum, totalCol;
            sfi2(rowNum,totalCol);
            while(totalCol--)
            {
                int colNum;
                sfi(colNum);
                visited[rowNum][colNum] = true;
            }
        }
        int initialX, initialY;
        sfi2(initialX,initialY);
        int endX, endY;
        sfi2(endX,endY);
        bfs(initialX,initialY);
        printf("%d\n",level[endX][endY]);
    }
}

