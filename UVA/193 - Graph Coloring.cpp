#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 10;
vector <int> adj[N];
int n, m, color[N];

bool check(int curNode)
{
    for(int child : adj[curNode])
        if(color[child] == 1)
            return false;
    return true;
}

void fun(int curNode, vector <int> &curAns, vector <int> &bestAns)
{
    if(curNode == n+1)
    {
        if((int)curAns.size() > (int)bestAns.size())
        {
            bestAns = curAns;
        }
        return;
    }
    if(check(curNode))
    {
        color[curNode] = 1;
        curAns.push_back(curNode);
        fun(curNode+1,curAns,bestAns);
        color[curNode] = 0;
        curAns.pop_back();
    }
    fun(curNode+1,curAns,bestAns);
}

void clean(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(adj[i].size())
        {
            adj[i].clear();
        }
        color[i] = 0;
    }
}

void solve()
{
    cin>>n>>m;
    clean(n);

    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> currAns, bestAns;
    fun(1,currAns,bestAns);
    cout<<bestAns.size()<<endl;
    for(int i=0; i<bestAns.size(); i++)
    {
        cout<<bestAns[i];
        if(i != bestAns.size()-1) cout<<" ";
    }
    cout<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++)
    {
        solve();
    }
}

/*

https://onlinejudge.org/external/1/193.pdf

*/
