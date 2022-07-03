#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 20;
int queen[N]; /// queen[i] = row number of queen at ith column
int column[N], diagonal1[N], diagonal2[N]; /// arrays to mark if there is a queen or not
int n, r, c;
int cnt;

void nqueen(int col)
{
    if(col == n+1)
    {
        if(queen[c] == r)
        {
            printf("%2d      ", ++cnt);
            for(int i=1; i<=n; i++)
            {
                printf("%d", queen[i]);
                if(i != n) printf(" ");
            }
            printf("\n");
        }
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(column[i] or diagonal1[i+col] or diagonal2[n+i-col]) continue;
        queen[col] = i;
        column[i] = diagonal1[i+col] = diagonal2[n+i-col] = 1;
        nqueen(col+1);
        column[i] = diagonal1[i+col] = diagonal2[n+i-col] = 0;
    }
}

void solve()
{
    n = 8;
    scanf("%d %d", &r, &c);
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    nqueen(1);
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tt;
    scanf("%d", &tt);
    for(int i=1; i<=tt; i++)
    {
        cnt = 0;
        solve();
        if(i != tt) printf("\n");
    }
}

/*

https://onlinejudge.org/external/7/750.pdf

*/

