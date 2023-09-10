#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int arr[N];
map<int,int> mp;

void solve()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        mp[arr[i]] = i;
    }    
    for(int i=1; i<=n; i++)
    {
        int need = m - arr[i];
        if(mp.find(need) != mp.end() && mp[need] != i)
        {
            cout<<i<<" "<<mp[need];
            return;
        }
    }
    cout<<"IMPOSSIBLE";
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