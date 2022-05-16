#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 2e5 +10;
int n, arr[N], block = (int)sqrt(N) + 1;;
vector <int> adj[N];
int start[N], finish[N], flatTree[2*N], currTime;
bool visited[N];
map <int,int> compress;

void euler_tour(int s)
{
    if(visited[s]) return;
    visited[s] = true;
    start[s] = currTime;
    flatTree[currTime] = s;
    currTime++;
    for(auto v : adj[s]){
        if(!visited[v]){
            euler_tour(v);
        }
    }
    finish[s] = currTime;
    flatTree[currTime] = s;
    currTime++;
}

struct query{
    int L, R, index;
    inline bool operator<(const query &Q) const {
        if(L / block != Q.L / block) return L < Q.L;
        return L / block & 1 ? R < Q.R : R > Q.R;
    }
};

query queries[N];
int freq[N], ans[N], cnt;

inline void add(int pos)
{
    if(freq[ flatTree[pos] ] == 0) cnt++;
    freq[ flatTree[pos] ]++;
}
inline void del(int pos)
{
    freq[ flatTree[pos] ]--;
    if(freq[ flatTree[pos] ] == 0) cnt--;
}

void solve()
{
    cin>>n;
    int idx = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(compress.find(arr[i]) == compress.end()){
            compress[ arr[i] ] = idx++;
        }
        arr[i] = compress[ arr[i] ];
    }
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    euler_tour(0);
    for(int i=0; i<2*n; i++){
        flatTree[i] = arr[ flatTree[i] ];
    }
    for(int i=0; i<n; i++){
        queries[i].L = start[i];
        queries[i].R = finish[i];
        queries[i].index = i;
    }
    sort(queries,queries+n);
    int currL = 0, currR = -1;
    for(int i=0; i<n; i++){
        int L = queries[i].L;
        int R = queries[i].R;
        int idx = queries[i].index;
        while(currR < R) add(++currR);
        while(currL < L) del(currL++);
        while(currR > R) del(currR--);
        while(currL > L) add(--currL);
        ans[idx] = cnt;
    }

    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
}

int main()
{
    int tt = 1;
    for(int i=1; i<=tt; i++){
        solve();
    }
}

/*
https://cses.fi/problemset/task/1139/
*/

