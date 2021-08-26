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

const int N = 55;
bool visited[N][N];
int level[N][N];
char mat[N][N];
int row,col,res;

bool check(int x, int y)
{
    return (x >= 0 and
            x < row and
            y>=0 and
            y < col and
            !visited[x][y]);
}

void bfs(int startX, int startY)
{
    mem(visited,false);
    mem(level,0);
    res = 1;

    visited[startX][startY] = true;
    level[startX][startY] = 1;

    queue <PII> q;
    q.push({startX,startY});

    while(!q.empty())
    {
        PII curr = q.front();
        q.pop();

        For(i,0,7)
        {
            int newX = curr.first + d8x[i];
            int newY = curr.second + d8y[i];
            if(check(newX,newY) and mat[newX][newY] - mat[curr.first][curr.second] == 1)
            {
                visited[newX][newY] = true;
                level[newX][newY] = level[curr.first][curr.second] + 1;
                res = max(res,level[newX][newY]);
                q.push({newX,newY});
            }
        }
    }
}


int main()
{
    int test = 1;
    while(1)
    {
        sfi2(row,col);
        if(!row and !col) break;

        For(i,0,row-1)
        For(j,0,col-1)
        cin>>mat[i][j];

        int maxi = 0;
        For(i,0,row-1)
            For(j,0,col-1)
                if(mat[i][j] == 'A')
                {
                    bfs(i,j);
                    maxi = max(maxi,res);
                }

        printf("Case %d: %d\n",test++, maxi);

        For(i,0,N-1)
            For(j,0,N-1)
                mat[i][j] = '.';

    }
    //main();
}

/*

1 26
ABCDEFGHIJKLMNOPQRSTUVWXYZ
4 3
ABE
CFG
BDH
ABC
27 1
A
B
C
D
E
F
G
H
I
J
K
L
M
N
O
P
Q
R
S
T
U
V
W
X
Y
Z
A
26 3
ABC
FED
GHI
LKJ
MNO
RQP
STU
XWV
YZA
AAB
ALE
ABM
NBE
AOE
ABP
ABQ
ARE
ASE
ABT
AUE
VBE
AWE
ABX
ABY
ABE
AAE
1 1
A
0 0

*/
