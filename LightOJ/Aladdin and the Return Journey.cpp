#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 30000 + 10;
int n, q;
vector <int> adj[N];
int startTime[N], finishTime[N], flatTree[2*N], cost[N], currTime;
int tree[8*N], treeCost[8*N];
bool visited[N];

void euler_tour(int s)
{
    if(visited[s]) return;
    visited[s] = true;
    startTime[s] = currTime;
    flatTree[currTime] = s;
    currTime++;
    for(auto v : adj[s])
    {
        if(!visited[v])
        {
            euler_tour(v);
        }
    }
    finishTime[s] = currTime;
    flatTree[currTime] = -s;
    currTime++;
}
void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = treeCost[e];
        return;
    }
    int mid = (b+e)/2;
    int left = node * 2;
    int right = left + 1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node] = tree[left] + tree[right];
}
void update(int node, int b, int e, int i, int value)
{
    if(b>i or e<i) return;
    if(b==e and b==i)
    {
        tree[node] = value;
        return;
    }
    int mid = (b+e)/2;
    int left = node * 2;
    int right = left + 1;
    if(mid >= i) update(left,b,mid,i,value);
    else update(right,mid+1,e,i,value);
    tree[node] = tree[left] + tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if(b>j or e<i) return 0;
    if(b>=i and e<=j) return tree[node];
    int mid = (b+e) / 2;
    int left = node * 2;
    int right = left + 1;
    int p =query(left,b,mid,i,j);
    int q = query(right,mid+1,e,i,j);
    return p+q;
}

const int lg = log2(N) + 3;
int parent[N], level[N], sparse_table[N][lg+1];

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
int LCA(int u, int v)
{
    /// level[v] >= level[u]
    if(level[v] < level[u]) swap(u,v);
    for(int i=lg; i>=0; i--)
    {
        if(sparse_table[v][i] != -1 and level[v]-(1<<i) >= level[u])
        {
            v = sparse_table[v][i];
        }
    }
    if(u==v) return u;
    for(int i=lg; i>=0; i--)
    {
        if(sparse_table[u][i] != -1 and sparse_table[v][i] != -1 and sparse_table[u][i] != sparse_table[v][i])
        {
            u = sparse_table[u][i];
            v = sparse_table[v][i];
        }
    }
    return parent[u];
}

void clean()
{
    for(int i=1; i<=n; i++)
    {
        if(adj[i].size()) adj[i].clear();
        visited[i] = false;
        startTime[i] = 0;
        finishTime[i] = 0;
        cost[i] = 0;
        tree[i] = 0;
        treeCost[i] = 0;
        parent[i] = 0;
        level[i] = 0;
    }
    for(int i=1; i<=2*n; i++) flatTree[i] = 0;
    currTime = 1;
}

void solve(int tt)
{
    cin>>n;
    clean();

    for(int i=1; i<=n; i++)
    {
        cin>>cost[i];
    }
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    euler_tour(1);

    for(int i=1; i<=2*n; i++)
    {
        if(flatTree[i] < 0)
        {
            int idx = -flatTree[i];
            treeCost[i] = -cost[idx];
        }
        else
        {
            int idx = flatTree[i];
            treeCost[i] = cost[idx];
        }
    }

    build(1,1,2*n);

    dfs(1,-1,1);
    parent[1] = 1;
    level[1] = 0;

    buildSparseTable();

    cin>>q;

    cout<<"Case "<<tt<<":"<<endl;
    for(int i=1; i<=q; i++)
    {
        int type;
        cin>>type;
        if(type == 1) /// update
        {
            int node, value;
            cin>>node>>value;
            node++;
            update(1,1,2*n,startTime[node],value);
            update(1,1,2*n,finishTime[node],-value);
            cost[node] = value;
        }
        else /// query
        {
            int u, v;
            cin>>u>>v;
            u++, v++;
            int lca = LCA(u,v);
            int left = query(1,1,2*n,startTime[lca],startTime[u]);
            int right = query(1,1,2*n,startTime[lca],startTime[v]);
            int ans = (left + right) - cost[lca];
            cout<<ans<<endl;
        }
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
    }
}

/*

Link : https://lightoj.com/problem/aladdin-and-the-return-journe
Sol : build segment tree with the help of euler tour tree because euler tour tree helps us to get the path sum.
Then from LCA of node U and V, get path sum of LCA to U and LCA to V, also subtract one LCA cost.

*/
