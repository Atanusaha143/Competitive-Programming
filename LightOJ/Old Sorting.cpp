#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 100 + 10;
int n, arr[N];

void solve(int tt)
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    int cnt = 0;
    start:
    for(int i=1; i<=n; i++)
    {
        if(arr[i] != i)
        {
            swap( arr[i], arr[ arr[i] ] );
            cnt++;
        }
    }
    if(!is_sorted(arr+1,arr+n+1)) goto start;
    cout<<"Case "<<tt<<": "<<cnt<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++)
    {
        solve(i);
    }
}

/*

https://lightoj.com/problem/old-sorting

*/
