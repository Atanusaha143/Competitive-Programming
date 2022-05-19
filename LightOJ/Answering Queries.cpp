#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e6 + 10;
int n, q;
ll arr[N], add[N], sub[N];

void clean()
{
    for(int i=0; i<N; i++){
        add[i] = 0;
        sub[i] = 0;
    }
}

void solve(int tt)
{
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    cout<<"Case "<<tt<<":"<<endl;
    for(int i=1,j=n-1; i<n and j>=1; i++,j--){
        add[i] = j;
    }
    for(int i=2,j=1; i<=n and j<n; i++,j++){
        sub[i] = j;
    }

    ll sum = 0;
    for(int i=1; i<=n; i++){
        ll jogkorbo = (add[i]*arr[i]*1ll);
        ll biyogkorbo = (sub[i]*arr[i]*1ll);
        sum += jogkorbo;
        sum -= biyogkorbo;
    }
    for(int i=1; i<=q; i++){
        int type;
        cin>>type;
        if(type == 1){
            cout<<sum<<endl;
        }
        else{
            int idx, val;
            cin>>idx>>val;
            idx++;
            ll badjabe = (add[idx]*arr[idx]*1ll);
            ll addhobe = (sub[idx]*arr[idx]*1ll);
            sum -= badjabe;
            sum += addhobe;
            arr[idx] = val;
            addhobe = (add[idx]*arr[idx]*1ll);
            badjabe = (sub[idx]*arr[idx]*1ll);
            sum += addhobe;
            sum -= badjabe;
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
https://lightoj.com/problem/answering-queries
*/
