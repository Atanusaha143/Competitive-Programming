#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

const int N = 1e6 + 10;
const int MOD = 1000003;

int n, r;
ll facts[N];

ll power_mod(ll base, ll power, ll mod)
{
    if(power==0) return 1ll;
    else if(power%2ll == 1){
        ll p1 = base % mod;
        ll p2 = (power_mod(base,power-1,mod))%mod;
        p1 = (ll)(p1*p2);
        return p1%mod;
    }
    else if(power%2ll == 0){
        ll p1 = (power_mod(base,power/2ll,mod))%mod;
        p1 = (ll)(p1*p1);
        return p1%mod;
    }
}

void precal()
{
    facts[0] = 1;
    facts[1] = 1;
    for(int i=2; i<N; i++){
        facts[i] = (facts[i-1] * i) % MOD;
    }
}

void solve(int tt)
{
    cin>>n>>r;
    ll r_fact = facts[r];
    ll nr_fact = facts[n-r];
    ll down = ((r_fact % MOD) * (nr_fact % MOD)) % MOD;
    ll n_fact = facts[n];
    ll down_inv = power_mod(down,MOD-2,MOD);
    ll ans = ((n_fact % MOD) * (down_inv % MOD)) % MOD;
    cout<<"Case "<<tt<<": "<<ans<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    precal();
    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        solve(i);
    }
}
/*
https://lightoj.com/problem/combinations
*/
