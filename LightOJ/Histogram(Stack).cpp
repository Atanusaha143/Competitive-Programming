#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 3e4 + 10;
int n, arr[N], leftlimit[N], rightlimit[N];

struct S{
    int idx, val;
    S(int _idx, int _val){
        idx = _idx;
        val = _val;
    }
};
stack <S> stk;

void solve(int tt)
{
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){ /// marking how far on the left-side the width can be equal as arr[i]
        while(!stk.empty()){
            int top_idx = stk.top().idx;
            int top_val = stk.top().val;
            if(top_val >= arr[i]){
                stk.pop();
            }
            else{
                break;
            }
        }
        if(stk.empty()){
            leftlimit[i] = 1;
        }
        else{
            int top_idx = stk.top().idx;
            leftlimit[i] = top_idx + 1;
        }
        stk.push(S(i,arr[i]));
    }

    while(!stk.empty()) stk.pop();

    for(int i=n; i>=1; i--){ /// marking how far on the right-side the width can be equal as arr[i]
        while(!stk.empty()){
            int top_idx = stk.top().idx;
            int top_val = stk.top().val;
            if(top_val >= arr[i]){
                stk.pop();
            }
            else{
                break;
            }
        }
        if(stk.empty()){
            rightlimit[i] = n;
        }
        else{
            int top_idx = stk.top().idx;
            rightlimit[i] = top_idx - 1;
        }
        stk.push(S(i,arr[i]));
    }

    int ans = -1;
    for(int i=1; i<=n; i++){
        int width = rightlimit[i] - leftlimit[i] + 1;
        int height = arr[i];
        int area = width * height;
        ans = max( area,ans );
    }
    cout<<"Case "<<tt<<": "<<ans<<endl;
    while(!stk.empty()) stk.pop();
}

int main()
{
    int tt = 1;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        solve(i);
    }
}

/*
https://lightoj.com/problem/histogram
Sol : From each bar of height H, we will mark the last position on the left side which has height at least H.
Also from that bar of height H, we will mark the last position on the right side which has height at least H.
So the area by taking that height (H) will be, area = (rightpos - leftpos + 1) * H
*/
