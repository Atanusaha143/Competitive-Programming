#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

const int N = 1e6 + 10;
int n, q, arr[N], tree[4*N], ans[N];

void update(int node, int b, int e, int i, int val)
{
    if(b>i or e<i) return;
    if(b==e and b==i){
        tree[node] = val;
        return;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = left+1;
    if(mid>=i) update(left,b,mid,i,val);
    else update(right,mid+1,e,i,val);
    tree[node] = tree[left]+tree[right];
}
int query(int node, int b, int e, int need)
{
    if(b==e){
        if(tree[node] == need) return e;
        return -1;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = left+1;
    if(need <= tree[left]){
        query(left,b,mid,need);
    }
    else{
        query(right,mid+1,e,need-tree[left]);
    }
}

void clean()
{
    for(int i=0; i<4*N; i++){
        tree[i] = 0;
    }
}

void solve(int tt)
{
    cin>>n>>q;
    int idx = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        ans[++idx] = arr[i];
        update(1,1,N,i,1);
    }
    cout<<"Case "<<tt<<":"<<endl;
    for(int i=1; i<=q; i++){
        char type;
        cin>>type;
        if(type == 'a'){
            int id;
            cin>>id;
            ans[++idx] = id;
            update(1,1,N,idx,1);
        }
        else{
            int k;
            cin>>k;
            int res = query(1,1,N,k);
            if(res == -1){
                cout<<"none"<<endl;
            }
            else{
                cout<<ans[res]<<endl;
                update(1,1,N,res,0);
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        clean();
        solve(i);
    }
}
/*
Link : https://lightoj.com/problem/diablo
Sol : At the very beginning, we will build the tree by marking every index as 1. This 1 means that the element
in the array is still present. At each deletion operation, we will update the particular index of the tree
as 0. At the time of query, we have to find for which index the rangeSum is equal to the queryIndex.
Finding can be done with Binary Search which will cost us extra logN. But we can also handle that with segment tree.
We just have to go the the sub-tree where we can find our rangeSum equal to the queryIndex.
*/
