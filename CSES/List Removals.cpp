#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int n, arr[N], brr[N];
LL tree[4*N];

void build(LL node, LL b, LL e)
{
    if(b == e){
        tree[node] = 1;
        return;
    }
    LL mid = (b+e)/2LL;
    LL left = node*2LL;
    LL right = left+1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node] = tree[left]+tree[right];
}
void update(LL node, LL b, LL e, LL i, LL val)
{
    if(b > i or e < i) return;
    if(b == e and b == i){
        tree[node] = val;
        return;
    }
    LL mid= (b+e)/2LL;
    LL left = node*2LL;
    LL right = left+1;
    if(mid>=i) update(left,b,mid,i,val);
    else update(right,mid+1,e,i,val);
    tree[node] = tree[left]+tree[right];
}
LL query(LL node, LL b, LL e, LL i, LL j)
{
    if(b > j or e < i) return 0;
    if(b >= i and e <= j) return tree[node];
    LL mid = (b+e)/2LL;
    LL left = node*2LL;
    LL right = left+1;
    LL p = query(left,b,mid,i,j);
    LL q = query(right,mid+1,e,i,j);
    return (LL)(p+q);
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++){
        cin>>brr[i];
    }
    build(1LL,1LL,n);
    for(int i=1; i<=n; i++){
        int l = 1, r = n, mid, ans;
        while(l <= r){
            mid = (l+r)/2;
            LL qans = query(1LL,1LL,n,1LL,mid);
            if(qans >= brr[i]){
                r = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout<<arr[ans]<<" ";
        update(1LL,1LL,n,ans,0);
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    for(int i=1; i<=tt; i++){
        solve();
    }
}

/*
https://cses.fi/problemset/task/1749/
*/
