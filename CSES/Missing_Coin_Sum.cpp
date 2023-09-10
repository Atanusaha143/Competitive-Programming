#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int arr[N];
map<int,bool> mp;

void solve()
{
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        mp[arr[i]] = true;
    }
    sort(arr+1, arr+n+1);

    long long cur_sum = 0;
    for(int i=1; i<=n+1; i++)
    {
        int prev_sum = cur_sum;
        cur_sum += arr[i];
        mp[cur_sum] = true;
        if(mp.find(i) == mp.end() && mp.find(prev_sum-i) == mp.end())
        {
            cout<<i;
            return;
        }
    }
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