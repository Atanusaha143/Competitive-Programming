
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 2e5 + 10;
const int lg = log2(N) + 3;
int sparse_table[N][lg+1];
int n, q, parent[N], level[N];
vector <int> adj[N];

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

void build()
{
    memset(sparse_table,-1,sizeof(sparse_table));
    for(int i=1; i<=n; i++)
    {
        sparse_table[i][0] = parent[i]; /// 2^0th node is the parent node
    }
    for(int j=1; j<=lg; j++) /// for every 2^jth node
    {
        for(int i=1; i<=n; i++) /// for every node
        {
            if( sparse_table[i][j-1] != -1 ) /// if we have calculated previously
            {
                sparse_table[i][j] = sparse_table[ sparse_table[i][j-1] ][j-1]; /// 8th parent of node i = 4th parent of i's 4th parent
            }
        }
    }
}

int LCA(int u, int v)
{
    /// level[v] >= level[u]
    if( level[v] < level[u]  ) swap(u,v);
    for(int i=lg; i>=0; i--)
    {
        if( sparse_table[v][i] != -1 and level[v]-(1<<i) >= level[u] ) /// making level[v] = level[u]
        {
            v = sparse_table[v][i];
        }
    }

    if( u == v ) return u; /// if u is an ancestor of v then the LCA is u

    for(int i=lg; i>=0; i--)
    {
        if( sparse_table[u][i] != -1 and sparse_table[v][i] != -1 and sparse_table[u][i] != sparse_table[v][i] )
        {
            u = sparse_table[u][i];
            v = sparse_table[v][i];
        }
    }
    return parent[u];
}

void solve(int tt)
{
    cin>>n>>q;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1,1);
    parent[1] = 1;
    level[1] = 0;

    build();
    for(int i=1; i<=q; i++)
    {
        int u, v;
        cin>>u>>v;
        int lca = LCA(u,v);
        int ans = level[u] + level[v] - (2*level[lca]);
        cout<<ans<<endl;
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    for(int i=1; i<=tt; i++)
    {
        solve(i);
    }
}

/*

Link https://cses.fi/problemset/task/1135/

Sol : First build the sparse table then for every node and apply :
Distance from node u to node v = level[v] + level[u] - 2*(level[ lca ])
level[v] = distance from root node to node v
level[u] = distance from root node to node u
Above the LCA node we were re-adding nodes at the time of level[u] and level[v], so we subtract that from our answer.

*/
