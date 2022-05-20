#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 2000 + 10;
int n, m;
int mat[N][N], arr[N][N];

struct Node{
    int height, idx;
};
Node tree[4*N];

void build(int node, int b, int e, int row)
{
    if(b == e){
        tree[node].height = arr[row][e];
        tree[node].idx = e;
        return;
    }
    int mid = (b+e)/2;
    int left = node * 2;
    int right = left + 1;
    build(left,b,mid,row);
    build(right,mid+1,e,row);
    if(tree[left].height < tree[right].height){
        tree[node].height = tree[left].height;
        tree[node].idx = tree[left].idx;
    }
    else{
        tree[node].height = tree[right].height;
        tree[node].idx = tree[right].idx;
    }
}
Node query(int node, int b, int e, int i, int j)
{
    if(b > j or e < i){
        Node x;
        x.height = INT_MAX;
        x.idx = INT_MAX;
        return x;
    }
    if(b >= i and e <= j) return tree[node];
    int mid = (b+e)/2;
    int left = node * 2;
    int right = left+1;
    Node p = query(left,b,mid,i,j);
    Node q = query(right,mid+1,e,i,j);
    if(p.height < q.height) return p;
    else return q;
}

int get_ans(int i, int j, int row)
{
    if(i == j) return arr[row][j];
    if(i > j) return 0;
    Node cur = query(1,1,m,i,j);
    int height = cur.height;
    int index = cur.idx;
    int width = (j - i) + 1;
    int area1 = height * width;
    int area2 = get_ans(i,index-1,row);
    int area3 = get_ans(index+1,j,row);
    return max({area1,area2,area3});
}
void cleanTree()
{
    for(int i=0; i<N; i++){
        tree[i].height = 0;
        tree[i].idx = 0;
    }
}
void cleanArr()
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = 0;
        }
    }
}

void solve(int tt)
{
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        string str;
        cin>>str;
        str = '_' + str;
        for(int j=1; j<=m; j++){
            int val = str[j] - '0';
            mat[i][j] = val;
        }
    }

    for(int i=1; i<=m; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(mat[j][i] == 0){
                cnt++;
                arr[j][i] = cnt;
            }
            else{
                cnt = 0;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        cleanTree();
        build(1,1,m,i);
        int cur_ans = get_ans(1,m,i);
        ans = max( ans, cur_ans);
    }
    cout<<"Case "<<tt<<": "<<ans<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        cleanArr();
        solve(i);
    }
}

/*
Link : https://lightoj.com/problem/new-land
Sol : Calculate height for each row. Then,
For each row, we take a range to calculate a area. Segment tree will give the minimum height and
the index. That index divides the range into two parts and we have to calculate for that divided two range
again in the same process.
*/
