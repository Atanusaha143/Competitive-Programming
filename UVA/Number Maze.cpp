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

// Grid direction array [4]
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
// Grid direction array [8]
int X8[8]={0,0,1,-1,-1,1,1,-1};
int Y8[8]={1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

struct Node
{
    int node_num_x, node_num_y, node_dist;
    Node(int _node_num_x, int _node_num_y, int _node_dist)
    {
        node_num_x = _node_num_x;
        node_num_y = _node_num_y;
        node_dist = _node_dist;
    }
};

bool operator<(Node A, Node B)
{
    return A.node_dist > B.node_dist;
}

int n,m;
const int N = 1010;
int mat[N][N], dist[N][N];

void djk(int startX, int startY)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dist[i][j] = 1e9;

    dist[startX][startY] = mat[startX][startY];

    priority_queue<Node> pq;
    pq.push(Node(startX,startY,mat[startX][startY]));

    while(!pq.empty())
    {
        Node u = pq.top();
        pq.pop();

        int unode_x = u.node_num_x;
        int unode_y = u.node_num_y;
        int udist = u.node_dist;

        if(udist == dist[unode_x][unode_y])
        {
            for(int i=0; i<4; i++)
            {
                int vnode_x = X[i] + unode_x;
                int vnode_y = Y[i] + unode_y;

                if(vnode_x >=0 and vnode_x <n and vnode_y >=0 and vnode_y <m)
                {
                    int newDistance = udist + mat[vnode_x][vnode_y];
                    if(newDistance < dist[vnode_x][vnode_y])
                    {
                        dist[vnode_x][vnode_y] = newDistance;
                        pq.push(Node(vnode_x,vnode_y,newDistance));
                    }
                }
            }
        }
    }
}

int main()
{
    int t;
    sfi(t);
    for(int tt=1; tt<=t; tt++)
    {
        sfi2(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                sfi(mat[i][j]);

        djk(0,0);
        printf("%d\n", dist[n-1][m-1]);

    }
    //main();
}

/*

2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5

*/

