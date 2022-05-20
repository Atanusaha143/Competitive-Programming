#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 10004;
int n, m, l;
vector <int> adj[N];
bool visited[N];
set <int> st;

void dfs(int s)
{
    if(visited[s]) return;
    visited[s] = true;
    st.erase(s);
    for(auto x : adj[s]){
        dfs(x);
    }
}

void clean()
{
    for(int i=0; i<N; i++){
        if(adj[i].size()){
            adj[i].clear();
        }
        visited[i] = false;
    }
    st.clear();
}

void solve()
{
    cin>>n>>m>>l;
    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        st.insert(i);
    }

    for(int i=1; i<=l; i++){
        int l;
        cin>>l;
        dfs(l);
    }
    int ans = n - st.size();
    cout<<ans<<endl;
}
int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        solve();
        clean();
    }
}

/*
https://onlinejudge.org/external/115/11518.pdf
*/
