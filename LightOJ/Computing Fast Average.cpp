#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define NL '\n'

const int N = 1e5;
LL n, q;
LL tree[4*N], lazy[4*N];

void update(LL node, LL b, LL e, LL i, LL j, LL val){
    LL mid = (b + e) / 2LL;
    LL left = node * 2LL;
    LL right = left + 1;
    if(lazy[node] >= 0){
        LL temp = lazy[node];
        lazy[node] = -1LL;
        tree[node] = (LL)(temp * (LL)(e - b + 1));
        if(b != e){
            lazy[left] = temp;
            lazy[right] = temp;
        }
    }
    if(b > j or e < i) return;
    if(b >= i and e <= j){
        LL temp = (LL)(val * (LL)(e - b + 1));
        tree[node] = temp;
        if(b != e){
            lazy[left] = val;
            lazy[right] = val;
        }
        return;
    }
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node] = tree[left] + tree[right];
}

LL query(LL node, LL b, LL e, LL i, LL j){
    LL mid = (b + e) / 2LL;
    LL left = node * 2LL;
    LL right = left + 1;
    if(lazy[node] >= 0){
        LL temp = lazy[node];
        lazy[node] = -1LL;
        tree[node] = (LL)(temp * (LL)(e - b + 1));
        if(b != e){
            lazy[left] = temp;
            lazy[right] = temp;
        }
    }
    if(b > j or e < i) return 0;
    if(b >= i and e <= j) return tree[node];
    LL p = query(left,b,mid,i,j);
    LL q = query(right,mid+1,e,i,j);
    return (LL)(p+q);
}


void clean(){
    for(int i=0; i<4*N; i++){
        tree[i] = 0;
        lazy[i] = -1LL;
    }
}

void solve(int tt){

    clean();

    cin>>n>>q;
    for(int i=1; i<=q; i++){
        int type;
        cin>>type;

        if(type == 1){ /// update
            LL l, r, val;
            cin>>l>>r>>val;
            l++, r++;
            update(1LL,1LL,n,l,r,val);
        }
        else{ /// query
            LL l, r;
            cin>>l>>r;
            l++, r++;
            LL ans = query(1LL,1LL,n,l,r);
            LL num = (r - l) + 1;
            if(ans % num){
                LL x = __gcd(ans,num);
                LL up = ans / x;
                LL down = num / x;
                cout<<up<<"/"<<down<<NL;
            }
            else{
                cout<<ans / num<<NL;
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        cout<<"Case "<<i<<":"<<NL;
        solve(tt);
    }
}

/*
https://lightoj.com/problem/computing-fast-average
*/

