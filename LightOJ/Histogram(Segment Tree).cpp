#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 3e4 + 10;
int n, arr[N];

struct bar{
    int height, idx;
};

bar tree[4*N];

void build(int node, int b, int e)
{
    if(b == e){
        tree[node].height = arr[e];
        tree[node].idx = e;
        return;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = left+1;
    build(left,b,mid);
    build(right,mid+1,e);
    if(tree[left].height < tree[right].height){
        tree[node].height = tree[left].height;
        tree[node].idx = tree[left].idx;
    }
    else{
        tree[node].height = tree[right].height;
        tree[node].idx = tree[right].idx;
    }
}

bar query(int node, int b, int e, int i, int j)
{
    if(b>j or e<i){
        bar x;
        x.height = INT_MAX;
        x.idx = INT_MAX;
        return x;
    }
    if(b>=i and e<=j) return tree[node];
    int mid = (b+e)/2;
    int left = node*2;
    int right = left+1;
    bar p = query(left,b,mid,i,j);
    bar q = query(right,mid+1,e,i,j);
    if(p.height < q.height) return p;
    else return q;
}

int get_ans(int i, int j)
{
    if(i==j) return arr[i];
    if(i>j) return 0;
    bar ans = query(1,1,n,i,j);
    int height = ans.height;
    int idx = ans.idx;
    int width = (j-i)+1;
    int area = height*width;
    int left_of_mine = get_ans(i,idx-1);
    int right_of_mine = get_ans(idx+1,j);
    return max({area,left_of_mine,right_of_mine});
}

void clean()
{
    for(int i=0; i<4*N; i++){
        tree[i].height = 0;
        tree[i].idx = 0;
    }
}

void solve(int tt)
{
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    int ans = get_ans(1,n);
    cout<<"Case "<<tt<<": "<<ans<<endl;
}
int main()
{
    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        clean();
        solve(i);
    }
}

/*
https://lightoj.com/problem/histogram
Sol: First we take a range to calculate a area. Segment tree will give the minimum height and
the index. That index divides the range into two parts and we have to calculate for that again
in the same process.
*/

