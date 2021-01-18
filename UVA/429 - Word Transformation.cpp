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

int dx[] = {0,1,0,-1}; // direction array
int dy[] = {-1,0,1,0};
int kx[] = {1,2,2,1,-1,-2,-2,-1}; // knights move
int ky[] = {2,1,-1,-2,-2,-1,1,2};

const int N = 250;
map <string,vector<string>> adj;
map <string,bool> visited;
map <string,int> level;

int bfs(string str1, string str2)
{
    visited.clear();
    level.clear();

    visited[str1] = true;
    level[str1] = 0;

    queue <string> q;
    q.push(str1);

    while(!q.empty())
    {
        string u = q.front(); q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            string v = adj[u][i];

            if(!(visited[v]))
            {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[str2];
}

int main()
{
    int t; sfi(t); For(tt,1,t){

        vector <string> vec;
        while(1)
        {
            string str;
            cin>>str;
            if(str[0]=='*') break;
            vec.PB(str);
        }


        For(i,0,sz(vec)-1)
        {
            string currStr = vec[i];
            int currLen = sz(currStr);
            For(j,i+1,sz(vec)-1)
            {
                string laterStr = vec[j];
                int laterLen = sz(laterStr);
                if(laterLen==currLen)
                {
                    int count = 0;
                    For(k,0,currLen-1)
                    {
                        if(currStr[k]!=laterStr[k])
                            count++;
                    }
                    if(count==1)
                    {
                        adj[currStr].PB(laterStr);
                        adj[laterStr].PB(currStr);
                    }
                }
            }
        }

        cin.ignore();
        string temp;
        while(getline(cin,temp) and temp!="")
        {
            stringstream sso;
            sso << temp;
            string in1, in2;
            sso >> in1 >> in2;
            int ans = bfs(in1,in2);
            cout<<in1<<" "<<in2<<" "<<ans<<NL;
        }

        if(t!=tt) cout<<NL;
    }

//    main();
}

