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

bool visited[500][500];
char mat[500][500];
int n,m,q;
int ans[500][500];

bool check(int newX, int newY)
{
    return (newX >=0 and
       newX < n and
       newY >= 0 and
       newY < m and
       visited[newX][newY] == false and
       (mat[newX][newY] == 'C' or mat[newX][newY] == '.'));
}

int bfs(int startX, int startY)
{
    visited[startX][startY] = true;

    vector <PII> currVis;
    queue <PII> q;
    q.push({startX,startY});
    currVis.PB({startX,startY});

    int cnt = 0;

    while(!q.empty())
    {
        PII curr = q.front();
        q.pop();

        For(i,0,3)
        {
            int newX = curr.first + d4x[i];
            int newY = curr.second + d4y[i];

            if(!visited[newX][newY] and check(newX,newY))
            {
                visited[newX][newY] = true;
                q.push({newX,newY});
                if(mat[newX][newY] == 'C') cnt++;
                currVis.PB({newX,newY});
            }
        }
    }

    For(i,0,sz(currVis)-1)
    {
        PII curr = currVis[i];
        int x = curr.first;
        int y = curr.second;
        if(visited[x][y])
        {
            ans[x][y] = cnt;
        }
    }
}

int main()
{
    int t; sfi(t); For(tt,1,t){

        sfi3(n,m,q);

        For(i,0,n-1)
        For(j,0,m-1)
        cin>>mat[i][j];

        mem(visited,false);
        For(i,0,n-1)
            For(j,0,m-1)
                if(mat[i][j] == '.' and !visited[i][j])
                    bfs(i,j);


        printf("Case %d:\n", tt);

        while(q--)
        {
            int x, y;
            sfi2(x,y);
            x--,y--;
            printf("%d\n", ans[x][y]);
        }
    }
    //main();
}

/*

1
4 5 2
..#..
.C#C.
##..#
..C#C
1 1
4 1

*/

