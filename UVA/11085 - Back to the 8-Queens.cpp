#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define endl '\n'

const int N = 10;
int queen[N]; /// queen[row] = column number of queen at that row
int column[N], diagonalL[N], diagonalR[N]; /// arrays to mark if there is a queen or not
int n, cnt, arr[N];
vector <pii> adj[100];

bool cmp(pii a, pii b)
{
    return a.first < b.first;
}

void nqueen(int row)
{
    if(row == n+1)
    {
        ++cnt;
        for(int i=1; i<=n; i++)
        {
            adj[cnt].push_back({queen[i],i});
        }
    }
    for(int col=1; col<=n; col++)
    {
        if(column[col] or diagonalL[n+col-row] or diagonalR[col+row]) continue;
        queen[row] = col;
        column[col] = diagonalL[n+col-row] = diagonalR[col+row] = 1;
        nqueen(row+1);
        column[col] = diagonalL[n+col-row] = diagonalR[col+row] = 0;
    }
}

void solve(int casenum)
{
    int mini = 100;
    for(int i=1; i<=cnt; i++)
    {
        int j = 0, cost = 0;
        for(pii x : adj[i])
        {
            int cur_row = x.second;
            int given_row = arr[++j];
            if(cur_row != given_row) cost++;
        }
        mini = min( mini,cost );
    }

    cout<<"Case "<<casenum<<": "<<mini<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    n = 8;
    nqueen(1);
    for(int i=1; i<=cnt; i++)
    {
        sort(adj[i].begin(),adj[i].end(),cmp);
    }

    int casenum = 0;
    while(cin>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5]>>arr[6]>>arr[7]>>arr[8])
    {
        solve(++casenum);
    }
}

/*
https://onlinejudge.org/external/110/11085.pdf
*/
