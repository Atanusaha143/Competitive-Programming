#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 2e5 + 10;
const int lg = log2(N) + 3;
int sparse_table[N][lg+1];
int n, q, arr[N], lgArr[N];

void build()
{
    memset(sparse_table,-1,sizeof(sparse_table));

    for(int i=0; i<n; i++)
    {
        sparse_table[i][0] = arr[i]; /// 2^0th node is the node itself
    }
    for(int j=1; j<=lg; j++) /// for every 2^jth index
    {
        for(int i=0; i+(1<<j)<=n; i++) /// for every index
        {
            if( sparse_table[i][j-1] != -1 ) /// if we have calculated previously
            {
                /// sparse_table[i][j] means the minimum in the subrange of length 2^j starting from the position i
                sparse_table[i][j] = min( sparse_table[i][j-1], sparse_table[ i+(1<<(j-1)) ][j-1] );
            }
        }
    }

    /// calculating j of 2^j which is <= x
    lgArr[1] = 0;
    for(int i=2; i<=n; i++)
    {
        lgArr[i]  = lgArr[ i/2 ] + 1;
    }
}

void solve(int tt)
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    build();
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int l, r;
        cin>>l>>r;
        int j = lgArr[ r-l+1 ];
        int mini = min( sparse_table[l][j], sparse_table[ r-(1<<j)+1 ][j] ); /// splitting the range into 2 parts of power of two's
        cout<<mini<<endl;
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    for(int i=1; i<=tt; i++)
    {
        solve(i);
    }
}

/*

Pre-processing : O(nlogn)
Query : O(1)

Link : https://www.spoj.com/problems/RMQSQ/


*/

