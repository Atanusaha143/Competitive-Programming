#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
#define endl '\n'

const int N = 16;
int n;
double cost[N][N], dp[(1 << N)];
pii arr[N];

double EuclideanDistance(double x1, double y1, double x2, double y2)
{
	double x = x2 - x1;
	double y = y2 - y1;
	double cur_dist = (x*x) + (y*y);
	cur_dist = sqrt(cur_dist);
	return cur_dist;
}

double fun(int mask)
{
    if(__builtin_popcount(mask) == n) return (double)0.00;
    if(dp[mask] != (double)1000000000.00) return dp[mask];
    double val = (double)1000000000.00;
    for(int i=0; i<n; i++)
    {
        if((mask & (1 << i)) == 0)
        {
            for(int j=i+1; j<n; j++)
            {
                if((mask & (1 << j)) == 0)
                {
                    int new_mask = mask | (1 << i) | (1 << j);
                    val = min( val, fun( new_mask ) + cost[i][j] );
                }
            }
        }
    }
    return dp[mask] = val;
}

void solve(int casenum)
{
    n *= 2;
    for(int i=0; i<n; i++)
    {
        string name;
        int x, y;
        cin>>name>>x>>y;
        arr[i].first = x;
        arr[i].second = y;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            double dist = EuclideanDistance((double)arr[i].first,(double)arr[i].second,(double)arr[j].first,(double)arr[j].second);
            cost[i][j] = dist;
        }
    }

    for(int i=0; i<=(1 << n); i++)
    {
        dp[i] = (double)1000000000.00;
    }

    double ans = fun(0);
    cout<<"Case "<<casenum<<": "<<fixed<<setprecision(2)<<ans<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int casenum = 0;
    while(1)
    {
        cin>>n;
        if(!n) break;
        solve(++casenum);
    }
}
