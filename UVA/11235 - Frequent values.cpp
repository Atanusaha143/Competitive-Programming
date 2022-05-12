#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define NL '\n';

const int N = 1e5 + 10;
int n, q, freq[N], start_idx[N], tree[4*N];
LL arr[N];
map <LL,LL> compress;

void build(int node, int b, int e)
{
    if(b == e){
        tree[node] = freq[ arr[e] ];
        return;
    }
    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node] = max(tree[left],tree[right]);
}
int query(int node, int b, int e, int i, int j)
{
    if(b > j or e < i) return INT_MIN;
    if(b >= i and e <= j){
        return tree[node];
    }
    int mid = (b + e) / 2;
    int left = 2 * node;
    int right = left + 1;
    int p = query(left,b,mid,i,j);
    int q = query(right,mid+1,e,i,j);
    return max(p,q);
}
void clean()
{
    for(int i=0; i<4*N; i++){
        tree[i] = 0;
    }
    for(int i=0; i<N; i++){
        start_idx[i] = 0;
        freq[i] = 0;
    }
    compress.clear();
}

void solve()
{
    cin>>q;
    LL idx = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        if(compress.find(arr[i]) == compress.end()){
            compress[ arr[i] ] = ++idx;
        }
    }
    for(int i=1; i<=n; i++){
        arr[i] = compress[ arr[i] ];
        freq[ arr[i] ]++;
        if(start_idx[ arr[i] ] == 0){
            start_idx[ arr[i] ] = i;
        }
    }
    build(1,1,n);
    for(int i=1; i<=q; i++){
        int l, r;
        cin>>l>>r;
        if(l == r){
            cout<<"1"<<NL;
        }else{
            int suru1 = start_idx[ arr[l] ];
            int sesh1 = (suru1 + freq[ arr[l] ]) - 1;
            sesh1 = min( sesh1,r );
            int bakiache1 = (sesh1 - l) + 1;
            int notunL = sesh1 + 1;
            int suru2 = start_idx[ arr[r] ];
            suru2 = max( suru2,l );
            int bakiache2 = (r - suru2) + 1;
            int notunR = suru2 - 1;
            int majhe = query(1,1,n,notunL,notunR);
            int ans = max({bakiache1,bakiache2,majhe});
            cout<<ans<<NL;
        }
    }
}

int main()
{
    while(1){
        cin>>n;
        if(n == 0) break;
        clean();
        solve();
    }
}

/*
https://onlinejudge.org/external/112/11235.pdf
*/

