#include <bits/stdc++.h>
using namespace std;

#define NL              '\n'
#define PINF            INT_MAX
#define NINF            INT_MIN
#define sz(x)           x.size()
#define PB              push_back
#define MP              make_pair
#define asort(x)        sort(all(x));
#define PI              (2.0*acos(0.0))
#define all(x)          x.begin(),x.end()
#define Now             cerr<<"Here"<<endl;
#define For(i, j, k)    for(int i = j; i <= k; i++)
#define Rof(i, j, k)    for(int i = j; i >= k; i--)
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL  my_rand(LL l, LL r) { return uniform_int_distribution<LL>(l, r) (rng); }

#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

///---------------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------------

const int N = 15 + 10;
const int MOD = 1000000007;

// Grid direction array [4]
int X[4]= {0,0,-1,1};
int Y[4]= {1,-1,0,0};

int n;
int level[N][N];
char mat[N][N],curmat[N][N];
bool visited[N][N];
map<char,PII>pos;

void clean()
{
    For(i,1,n)
    {
        For(j,1,n)
        {
            visited[i][j]=false;
            level[i][j]=0;
        }
    }
}

bool check(int x,int y)
{
    return (x>=1 and x<=n and y>=1 and y<=n and !visited[x][y] and curmat[x][y]!='#');
}

void genPos()
{
    For(i,1,n)
    {
        For(j,1,n)
        {
            if(mat[i][j]>='A' and mat[i][j]<='Z')
            {
                pos[mat[i][j]]={i,j};
            }
        }
    }
}

int bfs(char u,char v)
{
    int x=pos[u].first,y=pos[u].second;

    queue<PII>q;
    q.push({x,y});
    visited[x][y]=true;

    while (!q.empty())
    {
        PII unode=q.front(); q.pop();
        int xnode=unode.first,ynode=unode.second;
        if(curmat[xnode][ynode]==v)
        {
            return level[xnode][ynode];
        }
        For(i,0,3)
        {
            int newx=X[i]+xnode;
            int newy=Y[i]+ynode;
            if(check(newx,newy))
            {
                visited[newx][newy]=true;
                level[newx][newy]=level[xnode][ynode]+1;
                q.push({newx,newy});
            }
        }
    }
    return -1;
}

void makeMat(char u,char v)
{
    For(i,1,n)
    {
        For(j,1,n)
        {
            if((mat[i][j]=='.') or (mat[i][j]<=u) or (mat[i][j]<=v)) curmat[i][j]=mat[i][j];
            else curmat[i][j]='#';
        }
    }
}

void solve(int casenum)
{

    cin>>n;
    char highest_char='A';
    For(i,1,n)
    {
        For(j,1,n)
        {
            cin>>mat[i][j];
            if(mat[i][j]>='A' and mat[i][j]<='Z')
            {
                if(mat[i][j]>=highest_char)
                {
                    highest_char=mat[i][j];
                }
            }
        }
    }

    genPos();

    cout<<"Case "<<casenum<<": ";
    int cost=0;
    for(char c='A'; c<highest_char; c++)
    {
        char u=c,v=c+1;
        makeMat(u,v);
        clean();
        int steps=bfs(u,v);
        if(steps==-1)
        {
            cout<<"Impossible"<<NL;
            return;
        }
        else cost+=steps;
        if(v==highest_char) break;
    }
    cout<<cost<<NL;
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/gathering-food

Sol : As we have to follow alphabetical order, each time we can create a new matrix.
For example, there are 3 alphabet A,B,C in the given grid. So at first we have to go from
A to B without hitting any other alphabet. Here other alphabet greater than A and B are 
becoming obstable. So we can creat a new matrix which will only contain alphabet A and B. The dots(.) 
and obstacles(#) will remain same and moreover alphabet greater than A and B will be obstanle.
If it is impossible to go from A to B then it is sure that either there is no path from A to B or 
we are hitting any other alphabet. If it is possbile then we will count the minimum move to go from
A to B. This procedure is same for B to C but now we can keep alphabet A in our gird.
Finally if we can go from A to the highest alphabet then we have a result.

*/