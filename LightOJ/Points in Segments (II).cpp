#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define NL '\n';

const int N = 2e5;

map <int,int> compress;
map <int,bool> visited;
vector <pair<int,int>> segments;
vector <int> queris, vec;
int n, q, ans[N];

void clean(){
    compress.clear();
    visited.clear();
    segments.clear();
    queris.clear();
    vec.clear();
    for(int i=0; i<N; i++){
        ans[i] = 0;
    }
}

void solve(int tt){

    clean(); /// cleaning previous stored elements

    cin>>n>>q;
    for(int i=1; i<=n; i++){
        int l, r;
        cin>>l>>r;
        segments.push_back({l,r}); /// storing segments
        if(visited.find(l) == visited.end()){ /// checking if a point is already taken or not
            vec.push_back(l); /// storing all start points
            visited[l] = true; /// marking this point as taken
        }
        if(visited.find(r) == visited.end()){
            vec.push_back(r); /// storing all end points
            visited[r] = true;
        }
    }
    for(int i=1; i<=q; i++){
        int x;
        cin>>x;
        queris.push_back(x); /// storing query points
        if(visited.find(x) == visited.end()){
            vec.push_back(x);
            visited[x] = true;
        }
    }
    sort(vec.begin(),vec.end()); /// sorting all points for solution purpose
    vec.push_back(1e9); /// adding one extra point to make calculation easy
    int idx = 0;
    for(int i=0; i<vec.size(); i++){
        compress[ vec[i] ] = ++idx; /// compressing points as this can be upto 1e8
    }
    for(int i=0; i<segments.size(); i++){
        int l = compress[ segments[i].first ];
        int r = compress[ segments[i].second ];
        ans[l]++, ans[r+1]--; /// ++ means from that point a segment starts and -- means before that point a segment ends
    }
    for(int i=1; i<=idx; i++){
        ans[i] = ans[i] + ans[i-1]; /// prefix sums makes sure that in how many segments a particular point is intersected
    }
    for(int i=0; i<queris.size(); i++){
        LL res = ans[ compress[ queris[i] ] ];
        cout<<res<<NL;
    }
}

int main(){

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0); /// fast I/O method

    int tt = 1;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        cout<<"Case "<<i<<":"<<NL;
        solve(tt);
    }
}
