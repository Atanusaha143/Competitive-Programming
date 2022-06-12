#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e5 + 10;
const int lg = log2(N) + 3;
int n, q, cost[N];
vector <int> adj[N];

int parent[N], level[N];
void dfs(int s, int par, int dist)
{
    for(auto v : adj[s])
    {
        if(par != v)
        {
            dfs(v,s,dist+1);
            parent[v] = s;
            level[v] = dist;
        }
    }
}

int sparse_table[N][lg+1];
void buildSparseTable()
{
    memset(sparse_table,-1,sizeof(sparse_table));
    for(int i=1; i<=n; i++)
    {
        sparse_table[i][0] = parent[i];
    }
    for(int j=1; j<=lg; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sparse_table[i][j-1] != -1)
            {
                sparse_table[i][j] = sparse_table[ sparse_table[i][j-1] ][j-1];
            }
        }
    }
}

int get_ans(int node, int val)
{
    int ans = node;
    for(int i=lg; i>=0; i--)
    {
        int x = (1 << i);
        if(x <= level[node]) /// if the jumping level is <= to our current level
        {
            int temp = sparse_table[node][i];
            if(cost[temp] >= val) /// we will jump to the xth parent if it's value is >= given value
            {
                node = sparse_table[node][i]; /// jump to the level
                ans = node;
            }
        }
    }
    return ans;
}

void clean()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=lg; j++)
        {
            sparse_table[i][j] = 0;
        }
        if(adj[i].size()) adj[i].clear();
    }
}

void solve(int tt)
{
    cin>>n>>q;
    cost[1] = 1;
    for(int i=2; i<=n; i++)
    {
        int par, val;
        cin>>par>>val;
        par++;
        adj[i].push_back(par);
        adj[par].push_back(i);
        cost[i] = val;
    }

    dfs(1,-1,2);
    parent[1] = 1;
    level[1] = 1;
    buildSparseTable();

    cout<<"Case "<<tt<<":"<<endl;
    for(int i=1; i<=q; i++)
    {
        int node, val;
        cin>>node>>val;
        node++;
        int ans = get_ans(node,val);
        cout<<ans-1<<endl;
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++)
    {
        solve(i);
        clean();
    }
}

/*

Link :https://lightoj.com/problem/greatest-parent

*/
