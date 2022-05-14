#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 1001;
pair<int,int> arr[N];

bool cmp(pair <int,int> a, pair<int,int> b)
{
    if(a.second != b.second) return a.second < b.second;
    return a.first > b.first;
}

void precal()
{
    for(int i=1; i<=1000; i++){
        int limit = sqrt(i), cnt = 0;
        for(int j=1; j<=limit; j++){
            if(i % j == 0){
                if(j * j == i){
                    cnt++;
                }
                else{
                    cnt += 2;
                }
            }
        }
        arr[i].first = i;
        arr[i].second = cnt;
    }

    sort(arr+1,arr+N,cmp);
}

void solve(int tt)
{
    int n;
    cin>>n;
    int ans = arr[n].first;
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
https://lightoj.com/problem/false-ordering
*/
