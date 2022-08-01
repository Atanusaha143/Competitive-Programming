#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

const int N = 1e5 + 10;
int n, q, arr[N];
vector <int> tree[4*N];

void combine(vector <int> &node, vector <int> &left, vector <int> &right)
{
    int i=0, j=0;
    while(i < (int)left.size() and j < (int)right.size())
    {
        if(left[i] < right[j]) node.push_back(left[i]), i++;
        else node.push_back(right[j]), j++;
    }
    while(i < (int)left.size()) node.push_back(left[i]), i++;
    while(j < (int)right.size()) node.push_back(right[j]), j++;
}

void buildMergeSortTree(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].push_back(arr[e]);
        return;
    }
    int mid = (b+e) >> 1;
    int left = node << 1;
    int right = left + 1;
    buildMergeSortTree(left,b,mid);
    buildMergeSortTree(right,mid+1,e);
    combine(tree[node],tree[left],tree[right]);
}

int findResult(vector <int> &vec, int k)
{
    int l = 0, r = vec.size()-1, mid, ans = 0;
    while(l <= r)
    {
        mid = (l+r) >> 1;
        if(vec[mid] <= k)
        {
            ans = mid + 1;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

LL queryMergeSortTree(int node, int b, int e, int i, int j, int k)
{
    if(b > j or e < i) return 0;
    if(b >= i and e <= j)
    {
        int res = findResult(tree[node],k);
        return res;
    }
    int mid = (b+e) >> 1;
    int left = node << 1;
    int right = left + 1;
    int p = queryMergeSortTree(left,b,mid,i,j,k);
    int q = queryMergeSortTree(right,mid+1,e,i,j,k);
    return p+q;
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    buildMergeSortTree(1,1,n);
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int l, r, k;
        cin>>l>>r>>k;
        int ans = queryMergeSortTree(1,1,n,l,r,k);
        ans = (r-l+1) - ans;
        cout<<ans<<endl;
    }
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

https://www.spoj.com/problems/KQUERY/

*/

