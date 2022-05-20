#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 30;
vector <int> adj[N];
int parent[N];

int Find(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a != b){
        parent[b] = a;
    }
}

void clean()
{
    for(int i=0; i<N; i++){
        parent[i] = 0;
        adj[i].clear();
    }
}

void solve()
{
    char c;
    cin>>c;
    cin.ignore();
    string str;
    while(getline(cin,str) and str != ""){
        int u = str[0] - 'A' + 1;
        int v = str[1] - 'A' + 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int limit = c - 'A' + 1;
    for(int i=1; i<=limit+2; i++){
        parent[i] = i;
    }

    int ans = limit;
    for(int i=1; i<=27; i++){
        if(adj[i].size()){
            for(auto x : adj[i]){
                if( Find(i) != Find(x) ){
                    Union(i,x);
                    ans--;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        solve();
        if(i != tt){
            cout<<endl;
        }
        clean();
    }
}

/*
https://onlinejudge.org/external/4/459.pdf
*/
