#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n';

const int N = 1e5 + 10;
int n, c, q, freq[N], start_idx[N], tree[4*N];
int arr[N];

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
}

void solve(int tt)
{
    clean();

    cin>>n>>c>>q;
    LL idx = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++){
        freq[ arr[i] ]++;
        if(start_idx[ arr[i] ] == 0){
            start_idx[ arr[i] ] = i;
        }
    }
    build(1,1,n);
    cout<<"Case "<<tt<<":"<<endl;
    for(int i=1; i<=q; i++){
        int l, r;
        cin>>l>>r;
        if(l == r){
            cout<<"1"<<endl;
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
            cout<<ans<<endl;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        solve(i);
    }
}

/*
https://lightoj.com/problem/strongest-community
*/

