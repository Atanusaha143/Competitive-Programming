#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;
bool visited[N];
int dist[N];
vector <int> adj[N];

int bfs(int s, bool status)
{
    visited[s] = true;
    dist[s] = 0;
    queue <int> q;
    q.push(s);

    int max_dist = 0, max_node = s;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(auto v : adj[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                if(dist[v] > max_dist)
                {
                    max_dist = dist[v];
                    max_node = v;
                }
                q.push(v);
            }
        }
    }
    if(status == 0) return max_node;
    else return max_dist;
}

void solve()
{
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cur_max = bfs(1,0);
    for(int i=1; i<=n; i++)
    {
        dist[i] = 0;
        visited[i] = false;
    }
    int ans = bfs(cur_max,1);
    cout<<ans;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    for(int i=1; i<=tt; i++)
    {
        solve();
    }
}

/*

https://cses.fi/problemset/task/1131/

Sol : Choose a node and calculate farthest node from the chosen node and from that node calculate the farthest node.

*/

