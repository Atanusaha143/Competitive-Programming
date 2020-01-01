// https://codeforces.com/problemset/problem/994/A

#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
#define PI (2.0*acos(0.0))
#define sfi(x) scanf("%d",&x)
#define sfl(x) scanf("%I64d",&x)
#define sfd(x) scanf("%lf",&x)
#define sfs(x) scanf("%s",x)
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;


int main()
{
    int n,m,k=0;
    sfi(n); sfi(m);
    int nrr[n],mrr[m],res[m];
    for(int i=0; i<n; i++) sfi(nrr[i]);
    for(int i=0; i<m; i++) sfi(mrr[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(nrr[i]==mrr[j]) {res[k]=nrr[i]; k++;}
        }
    }
    for(int i=0; i<k; i++) cout<<res[i]<<" ";
}
