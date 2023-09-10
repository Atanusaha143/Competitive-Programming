#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
int arr[N];

long long getCost(int mid)
{
    long long cost = 0;
    for(int i=1; i<=n; i++)
    {
        cost += abs(arr[i] - mid);
    }
    return cost;
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    sort(arr+1, arr+n+1);

    int l = 0, r = 1e9;
    long long ans;
    while(l <= r)
    {
        int mid1 = l + ((r - l) / 3LL);
        int mid2 = r - ((r - l) / 3LL);
        long long cost1 = getCost(mid1);
        long long cost2 = getCost(mid2);
        if(cost1 < cost2)
        {
            ans = cost1;
            r = mid2 - 1;
        }
        else l = mid1 + 1;
    }
    cout<<ans;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve();
    }
}