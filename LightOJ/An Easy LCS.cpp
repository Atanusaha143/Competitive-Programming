#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

string s,t;
int dp[101][101];
int n,m;

int fun(int i,int j)
{
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int val=0;
    if(s[i]==t[j])
    {
        val=max(val,fun(i+1,j+1)+1);
    }
    else
    {
        val=max(val,fun(i+1,j));
        val=max(val,fun(i,j+1));
    }
    return dp[i][j]=val;
}

void solve(int casenum)
{
    cin>>s>>t;
    n=s.size(), m=t.size();
    memset(dp,-1,sizeof(dp));
    int lcs_len=fun(0,0);

    string ans;
    int ii=0,jj=0;
    for(int k=0;k<lcs_len;k++)
    {
        char c=126;
        int next_i,next_j;
        for(int i=ii;i<s.size();i++)
        {
            for(int j=jj;j<t.size();j++)
            {
                if(s[i]==t[j])
                {
                    if(fun(i+1,j+1)+1==lcs_len-k)
                    {
                        if(s[i]<c)
                        {
                            c=s[i];
                            next_i=i+1;
                            next_j=j+1;
                        }
                    }
                }
            }
        }
        ii=next_i;
        jj=next_j;
        ans.push_back(c);
    }

    if(ans.empty()) ans=":(";
    cout<<"Case "<<casenum<<": "<<ans<<endl;
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
}

/*

https://lightoj.com/problem/an-easy-lcs

*/
