#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define endl              '\n'
#define PI              (2.0*acos(0.0))
#define PB              push_back
#define MP              make_pair
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
#define now             cout<<"Here"<<endl;
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define READ            freopen("input.txt","r",stdin)
#define WRITE           freopen("output.txt","w",stdout)
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// *find_by_order = value of an index, order_of_key = index of a value where it should be
//typedef tree<PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

//LL power_mod(LL base, LL power, LL mod){
//    if(power==0) return 1LL;
//    else if(power%2LL == 1){
//        LL p1 = base % mod; LL p2 = (power_mod(base,power-1,mod))%mod;
//        p1 = (LL)(p1*p2); return p1%mod;
//    }
//    else if(power%2LL == 0){
//        LL p1 = (power_mod(base,power/2LL,mod))%mod; p1 = (LL)(p1*p1);
//        return p1%mod;
//    }
//}

//LL original_power(LL base, LL power){
//    if(power==0) return 1LL;
//    else if(power%2LL == 1){
//        LL p1 = base; LL p2 = (original_power(base,power-1));
//        p1 = (LL)(p1*p2); return p1;
//    }
//    else if(power%2LL == 0){
//        LL p1 = (original_power(base,power/2LL)); p1 = (LL)(p1*p1);
//        return p1;
//    }
//}

// Grid direction array [4] R-L-U-D
int X[4]= {0,0,-1,1};
int Y[4]= {1,-1,0,0};
// Grid direction array [8]
//int X8[8]= {0,0,1,-1,-1,1,1,-1};
//int Y8[8]= {1,-1,0,0,-1,-1,1,1};
//// Knight Direction Array
//int KX[8] = {1,1,2,2,-1,-1,-2,-2};
//int KY[8] = {2,-2,1,-1,2,-2,1,-1};

///------------------------------------------------------------------------------------------------------

const int N = 1000 + 10;
const int MOD = 1000000007;

int n, m, startX, startY, endX, endY;
PII parent[N][N];
char mat[N][N];
bool visited[N][N];
vector <char> dir, ans;

bool check(int x, int y)
{
    return ( x >= 1 and x <=n and y >= 1 and y <= m and !visited[x][y] and mat[x][y] != '#');
}

bool bfs(int x, int y)
{
    visited[x][y] = true;
    queue <PII> q;
    q.push({x,y});
    parent[x][y] = {-1,-1};
    bool paisi = false;

    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int newX = curX + X[i];
            int newY = curY + Y[i];
            if(check(newX,newY))
            {
                visited[newX][newY] = true;
                parent[newX][newY] = {curX,curY};
                q.push({newX,newY});
                if(newX == startX and newY == startY) paisi = true;
            }
        }
    }
    return paisi;
}

void solve(int casenum)
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>mat[i][j];
            if(mat[i][j] == 'A') startX = i, startY = j;
            else if(mat[i][j] == 'B') endX = i, endY = j;
        }
    }

    bool res = bfs(endX,endY);
    if(res)
    {
        cout<<"YES"<<endl;
        vector <char> ans;
        int tempX = startX, tempY = startY;
        while(1)
        {
            int parX = parent[tempX][tempY].first;
            int parY = parent[tempX][tempY].second;
            for(int i=0; i<4; i++)
            {
                int newX = tempX + X[i];
                int newY = tempY + Y[i];
                if(newX == parX and newY == parY)
                {
                    ans.PB(dir[i]);
                    tempX = newX;
                    tempY = newY;
                    break;
                }
            }
            if(tempX == endX and tempY == endY) break;
        }
        cout<<ans.size()<<endl;
        for(char c : ans) cout<<c;
    }
    else cout<<"NO";

}

int main()
{
//    IOS;

//    READ;
//    WRITE;

    dir.PB('R');
    dir.PB('L');
    dir.PB('U');
    dir.PB('D');

    int t = 1;
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

https://cses.fi/problemset/task/1193/

*/

