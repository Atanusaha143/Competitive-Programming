#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define endl              '\n'
#define sz(x)           x.size()
#define PINF            INT_MAX
#define NINF            INT_MIN
#define PI              (2.0*acos(0.0))
#define PB              push_back
#define MP              make_pair
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
#define now             cout<<"Here"<<endl;
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define READ            freopen("input.txt","r",stdin)
#define WRITE           freopen("output.txt","w",stdout)
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef pair <int,int> pii;
typedef pair <LL,LL> pll;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// *find_by_order = value of an index, order_of_key = index of a value where it should be
//typedef tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

//// Grid direction array [4]
//int X[4]= {0,0,-1,1};
//int Y[4]= {1,-1,0,0};
// Grid direction array [8]
//int X8[8]= {0,0,1,-1,-1,1,1,-1};
//int Y8[8]= {1,-1,0,0,-1,-1,1,1};
//// Knight Direction Array
//int KX[8] = {1,1,2,2,-1,-1,-2,-2};
//int KY[8] = {2,-2,1,-1,2,-2,1,-1};

///------------------------------------------------------------------------------------------------------

const int N = 20 + 10;
const int MOD = 1000000007;

vector <int> adj[N];
vector <int> inputs1, inputs2, res;
vector <string> ans;
int indegree[N];
bool visited[N];
string variables, constraints;

void genAllTopoSort()
{
    bool flag = false;
    for(int i=0; i<inputs1.size(); i++)
    {
        if(indegree[ inputs1[i] ] == 0 and !visited[ inputs1[i] ])
        {
            for(int j=0; j<adj[ inputs1[i] ].size(); j++)
            {
                indegree[ adj[ inputs1[i] ][j] ]--;
            }

            visited[ inputs1[i] ] = true;
            res.push_back( inputs1[i] );
            genAllTopoSort();

            visited[ inputs1[i] ] = false;
            res.pop_back();
            for(int j=0; j<adj[ inputs1[i] ].size(); j++)
            {
                indegree[ adj[ inputs1[i] ][j] ]++;
            }
            flag = true;
        }
    }

    if(!flag)
    {
        string x;
        for(int i=0; i<res.size(); i++)
        {
            char c = (res[i] - 1) + 'a';
            x.PB(c);
        }
        ans.PB(x);
    }
}

void clean()
{
    for(int i=0; i<N; i++)
    {
        if(adj[i].size())
        {
            adj[i].clear();
        }
    }
    inputs1.clear();
    inputs2.clear();
    res.clear();
    ans.clear();
    mem(indegree,0);
    mem(visited,false);
}

void solve(int casenum)
{
    while(getline(cin,variables) and getline(cin,constraints))
    {
        clean();

        if(casenum != 1) cout<<endl;
        casenum++;

        for(char c : variables)
        {
            if(c != ' ' and c != '\n')
            {
                int x = (int)(c - 'a') + 1;
                inputs1.push_back(x);
            }
        }
        for(char c : constraints)
        {
            if(c != ' ' and c != '\n')
            {
                int x = (int)(c - 'a') + 1;
                inputs2.push_back(x);
            }
        }

        for(int i=0; i<inputs2.size(); i+=2)
        {
            int u = inputs2[i];
            int v = inputs2[i+1];
            adj[u].PB(v);
            indegree[v]++;
        }
        genAllTopoSort();

        asort(ans);
        for(string x : ans) cout<<x<<endl;
    }
}

int main()
{
//    IOS;

//    READ;
//    WRITE;

    int t = 1;
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

https://onlinejudge.org/external/1/124.pdf

*/

