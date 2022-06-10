#include<bits/stdc++.h>
using namespace std;

const int N = 50000 + 10;
const int lg = log2(N) + 3;
int arr[N], sparse_table[N+1][lg], log_arr[N];
int n, m;

void buildSparseTable()
{
    for(int i=0; i<n; i++)
    {
        sparse_table[i][0] = arr[i];
    }
    for(int j=1; j<=lg; j++)
    {
        for(int i=0; i+(1<<j)<=n; i++)
        {
            if(sparse_table[i][j-1] != -1)
            {
                sparse_table[i][j] = max( sparse_table[i][j-1],  sparse_table[ i+(1<<(j-1)) ][j-1]);
            }
        }
    }
    log_arr[1] = 0;
    for(int i=2; i<=n; i++)
    {
        log_arr[i] = log_arr[i/2] + 1;
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    buildSparseTable();

    int ans = 0;
    for(int i=1; i<=m; i++)
    {
        int l, r;
        cin>>l>>r;
        l--, r--;
        if(l < r)
        {
            int newR = r - 1;
            int j = log_arr[ newR-l+1 ];
            int cur_max = max( sparse_table[l][j], sparse_table[ newR-(1<<j)+1 ][j] );
            if(arr[l] == cur_max)
            {
                ans++;
            }
        }
    }
    cout<<ans;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    for(int i=1; i<=tt; i++)
    {
        solve();
    }
}

/*

https://www.spoj.com/problems/THRBL/

*/
