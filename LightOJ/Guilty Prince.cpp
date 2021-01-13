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

int row, col;
bool visited[25][25];
char mat[25][25];

// checking if Prince is able to go through a land which he hasn't visited yet
bool check(int newX, int newY)
{
    return newX >=0 and newY >= 0 and newX < row
    and newY < col and visited[newX][newY]==false
    and mat[newX][newY]=='.';
}

int bfs(int startX, int startY)
{
    int count = 1;
    queue <PII> q;
    visited[startX][startY] = true;
    q.push({startX,startY});

    while(!q.empty())
    {
        PII curr = q.front();
        q.pop();

        For(i,0,3)
        {
            int newX = curr.fi + dx[i];
            int newY = curr.se + dy[i];

            if(check(newX,newY))
            {
                q.push({newX,newY});
                visited[newX][newY] = true;
                count++;
            }
        }
    }
    return count;
}

int main()
{

    int t; sfi(t); For(tt,1,t){

        mem(visited,false);

        sfi2(row,col);
        int startX, startY;

        For(i,0,col-1)
            For(j,0,row-1)
            {
                cin>>mat[j][i];
                // initial position of the prince
                if(mat[j][i]=='@')
                {
                    startX = j;
                    startY = i;
                }
            }

        int ans = bfs(startX,startY);

        printf("Case %d: %d\n", tt, ans);
    }

//    main();
}

