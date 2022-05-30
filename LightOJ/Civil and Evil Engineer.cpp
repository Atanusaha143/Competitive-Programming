#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 12000 + 10;
int n, parent[N];
ll maxi, mini;

struct Edge{
    int u, v, w;
};
Edge arr[N];
bool cmpMin(Edge a, Edge b)
{
    return a.w < b.w;
}
bool cmpMax(Edge a, Edge b)
{
    return a.w > b.w;
}
int Find(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b, int idx, bool flag)
{
    a = Find(a);
    b = Find(b);
    if(a != b){
        parent[a] = b;
        if(flag){
            mini += arr[idx].w;
        }
        else{
            maxi += arr[idx].w;
        }
    }
}
void clean()
{
    maxi = 0, mini = 0;
}

void solve(int tt)
{
    cin>>n;
    int u, v, w;
    int k = 0;
    while(1){
        cin>>u>>v>>w;
        if(u == 0 and v == 0 and w == 0) break;
        arr[k].u = u;
        arr[k].v = v;
        arr[k].w = w;
        k++;
    }
    sort(arr,arr+k,cmpMin);
    for(int i=0; i<=n+2; i++){
        parent[i] = i;
    }
    for(int i=0; i<k; i++){
        int a = arr[i].u;
        int b = arr[i].v;
        Union(a,b,i,true);
    }
    sort(arr,arr+k,cmpMax);
    for(int i=0; i<=n+2; i++){
        parent[i] = i;
    }
    for(int i=0; i<k; i++){
        int a = arr[i].u;
        int b = arr[i].v;
        Union(a,b,i,false);
    }
    ll ans = maxi + mini;
    cout<<"Case "<<tt<<": ";
    if(ans % 2){
        cout<<ans<<"/2"<<endl;
    }
    else{
        cout<<ans/2<<endl;
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        solve(i);
        clean();
    }
}

/*
https://lightoj.com/problem/civil-and-evil-engineer
*/
