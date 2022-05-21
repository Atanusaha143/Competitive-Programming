#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 110;
int n, m;
map <string,int> compress1;
map <int,string> compress2;
int indegree[N];
vector <int> adj[N];
vector <int> ans;

void clean()
{
    compress1.clear();
    compress2.clear();
    for(int i=0; i<N; i++){
        indegree[i] = 0;
        if(adj[i].size()){
            adj[i].clear();
        }
    }
    ans.clear();
}

void kahn(int n)
{
    set <int> st; /// if there is no relation then two drinks then the drink which appears first in the input will get prioritize.
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            st.insert(i);
        }
    }

    while(!st.empty()){
        int u = *st.begin();
        st.erase(u);
        ans.push_back(u);
        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                st.insert(v);
            }
        }
    }
}

void solve(int testcase)
{
    for(int i=1; i<=n; i++){
        string str;
        cin>>str;
        compress1[str] = i;
        compress2[i] = str;
    }
    int m;
    cin>>m;
    for(int i=1; i<=m; i++){
        string su, sv;
        cin>>su>>sv;
        int u = compress1[su];
        int v = compress1[sv];
        adj[u].push_back(v);
        indegree[v]++;
    }

    kahn(n);

    cout<<"Case #"<<testcase<<": Dilbert should drink beverages in this order:";
    for(int i=0; i<ans.size(); i++){
        string str = compress2[ ans[i] ];
        cout<<" "<<str;
    }
    cout<<"."<<endl<<endl;
}

int main()
{
    int testcase = 0;
    while(cin>>n){
        solve(++testcase);
        clean();
    }
}

