#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define endl '\n'

const int N = 1e5 + 10;
const int lg = log2(N) + 3;
int sparse_table[N][lg+1], sparse_table_min[N][lg+1], sparse_table_max[N][lg+1];
int n, q, parent[N], level[N], value[N];
vector <int> adj[N], cost[N];

void dfs(int s, int par, int dist)
{
    for(int i=0; i<adj[s].size(); i++)
    {
        int v = adj[s][i];
        if(par != v)
        {
            value[v] = cost[s][i]; /// moving edge cost to node cost
            dfs(v,s,dist+1);
            parent[v] = s;
            level[v] = dist;
        }
    }
}

void buildSparseTable()
{
    for(int i=0; i<=n; i++) /// reseting everything
    {
        for(int j=0; j<=lg; j++)
        {
            sparse_table[i][j] = -1;
            sparse_table_min[i][j] = INT_MAX;
            sparse_table_max[i][j] = -1;
        }
    }

    for(int i=1; i<=n; i++) /// assigning values
    {
        sparse_table[i][0] = parent[i];
        sparse_table_min[i][0] = value[i];
        sparse_table_max[i][0] = value[i];
    }
    sparse_table_min[1][0] = INT_MAX; /// assigning values for correct comparing with next values
    sparse_table_max[1][0] = -1;

    for(int j=1; j<=lg; j++) /// building sparse table
    {
        for(int i=1; i<=n; i++)
        {
            if( sparse_table[i][j-1] != -1 )
            {
                sparse_table[i][j] = sparse_table[ sparse_table[i][j-1] ][j-1];
                sparse_table_min[i][j] = min( sparse_table_min[i][j-1], sparse_table_min[ sparse_table[i][j-1] ][j-1]);
                sparse_table_max[i][j] = max( sparse_table_max[i][j-1], sparse_table_max[ sparse_table[i][j-1] ][j-1]);
            }
        }
    }
}

pii get_ans(int u, int v)
{
    if( level[v] < level[u]  ) swap(u,v);
    int mini_left = INT_MAX, maxi_left = -1, mini_right = INT_MAX, maxi_right = -1;
    for(int i=lg; i>=0; i--)
    {
        if( sparse_table[v][i] != -1 and level[v]-(1<<i) >= level[u] )
        {
            mini_right = min( mini_right,sparse_table_min[v][i] );
            maxi_right = max( maxi_right,sparse_table_max[v][i] );
            v = sparse_table[v][i];
        }
    }

    if( u == v ) return pii(mini_right, maxi_right);

    for(int i=lg; i>=0; i--)
    {
        if( sparse_table[u][i] != -1 and sparse_table[v][i] != -1 and sparse_table[u][i] != sparse_table[v][i] )
        {
            mini_left = min( mini_left,sparse_table_min[u][i] );
            maxi_left = max( maxi_left,sparse_table_max[u][i] );
            mini_right = min( mini_right,sparse_table_min[v][i] );
            maxi_right = max( maxi_right,sparse_table_max[v][i] );
            u = sparse_table[u][i];
            v = sparse_table[v][i];
        }
    }
    mini_left = min( mini_left, min(value[u],value[v]) );
    maxi_left = max( maxi_left, max(value[u],value[v]) );
    mini_right = min( mini_right, min(value[u],value[v]) );
    maxi_right = max( maxi_right, max(value[u],value[v]) );
    return pii( min(mini_left,mini_right), max(maxi_left,maxi_right) );
}

void clean()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=lg; j++)
        {
            sparse_table[i][j] = 0;
            sparse_table_min[i][j] = 0;
            sparse_table_max[i][j] = 0;
        }
        if(adj[i].size()) adj[i].clear();
        if(cost[i].size()) cost[i].clear();
    }
}

void solve(int tt)
{
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    dfs(1,-1,1);
    parent[1] = 1;
    level[1] = 0;
    buildSparseTable();
    cin>>q;
    cout<<"Case "<<tt<<":"<<endl;
    for(int i=1; i<=q; i++)
    {
        int u, v;
        cin>>u>>v;
        pii ans = get_ans(u,v);
        cout<<ans.first<<" "<<ans.second<<endl;
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

https://lightoj.com/problem/min-max-roads

Sol :
1. get minimum and maximum from path v to LCA
2. get minimum and maximum from path u to LCA
3. return minimum and maximum from both

*/
