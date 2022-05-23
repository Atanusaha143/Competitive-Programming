#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 20;
ll n, m;
ll arr[N];

ll lcm(ll a,ll b) { return (a/__gcd(a,b))*b; }

ll inclusion_exclusion(ll n, ll m)
{
    ll limit = 1 << m; /// total subset size
    ll ans = 0;
    for(ll mask=1; mask<limit; mask++){
        ll set_lcm = 1, set_size = 0;
        for(int i=0; i<m; i++){
            if(mask & (1 << i)){
                set_lcm = lcm( set_lcm,arr[i] );
                set_size++;
            }
        }
        ll total_divs = n / set_lcm;
        if(set_size % 2){
            ans += total_divs; /// if the set size is odd then we are including the result
        }
        else{
            ans -= total_divs; /// if the set size is even then we are excluding the result
        }
    }
    return ans;
}

void solve(int tt)
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    ll ans = n - inclusion_exclusion(n,m);
    cout<<"Case "<<tt<<": "<<ans<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        solve(i);
    }
}

/*
https://lightoj.com/problem/helping-cicada

A U B U C = (A + B + C) - (A ∩ B) - (A ∩ C) - (B ∩ C) + (A ∩ B ∩ C)

*/

