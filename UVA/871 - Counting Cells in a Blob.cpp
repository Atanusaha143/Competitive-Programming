#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 30;

int mat[N][N];
bool visited[N][N];
int n, m;
int X[] = {-1, 0, 1, -1, 1, -1,  0,  1};
int Y[] = {1,  1, 1,  0, 0, -1, -1, -1};

bool check(int newX, int newY)
{
    return (newX >= 0 and newY >= 0 and newX < n and newY < m and visited[newX][newY] == false and mat[newX][newY] == 1);
}

int bfs(int startX, int startY)
{
    int cnt = 1;
    queue <pii> q;
    q.push({startX,startY});
    visited[startX][startY] = true;

    while(!q.empty()){
        pii cur = q.front();
        q.pop();

        for(int i=0; i<8; i++){
            int newX = cur.first + X[i];
            int newY = cur.second + Y[i];
            if(check(newX,newY)){
                q.push({newX,newY});
                visited[newX][newY] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

void clean()
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mat[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void solve()
{
    string str;
    vector <string> vec;
    while(getline(cin,str) and str != ""){
        vec.push_back(str);
    }

    n = vec.size();
    for(int i=0; i<vec.size(); i++){
        string cur = vec[i];
        m = cur.size();
        for(int j=0; j<cur.size(); j++){
            mat[i][j] = cur[j] - '0';
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] and mat[i][j] == 1){
                ans = max( ans,bfs(i,j) );
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int tt;
    cin>>tt;
    getchar();
    getchar();
    for(int i=1; i<=tt; i++){
        solve();
        if(i != tt){
            cout<<endl;
        }
        clean();
    }
    return 0;
}

