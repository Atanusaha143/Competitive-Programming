#include<bits/stdc++.h>
using namespace std;
#define NL '\n';

const int N = 1e5 + 10;
int n, q, k;
int arr[N];

struct query{
    int index, L, R;
    inline bool operator<(const query &Q) const {
		if(L/k!=Q.L/k) return L<Q.L;
		return L/k&1?R<Q.R:R>Q.R;
    }
};

query queries[N];
int freq[N], ans[N], cnt;
void add(int pos)
{
    if(freq[ arr[pos] ] == 0) cnt++; /// count increases when a new element is found in a segment
    freq[ arr[pos] ]++;
}
void del(int pos)
{
    freq[ arr[pos] ]--;
    if(freq[ arr[pos] ] == 0) cnt--; /// count decreases when an element does not occur in a segment anymore
}
void clean()
{
    for(int i=0; i<N; i++){
        freq[i] = 0;
        ans[i] = 0;
    }
    cnt = 0;
}

void solve()
{
    clean();

    cin>>n>>q;
    k = sqrt(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<q; i++){
        cin>>queries[i].L>>queries[i].R;
        queries[i].L--; queries[i].R--;
        queries[i].index = i;
    }
    sort(queries,queries+q);

    int currL = 0, currR = -1;
    for(int i=0; i<q; i++){
        int L = queries[i].L;
        int R = queries[i].R;
        int idx = queries[i].index;
        while(currR < R) add(++currR);
        while(currL < L) del(currL++);
        while(currR > R) del(currR--);
        while(currL > L) add(--currL);
        ans[idx] = cnt;
    }

    for(int i=0; i<q; i++) cout<<ans[i]<<NL;
}


int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt = 1;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        cout<<"Case "<<i<<":"<<NL;
        solve();
    }
}

/*
https://lightoj.com/problem/fast-queries
*/

