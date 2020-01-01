// https://codeforces.com/problemset/problem/987/A

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
    int n;
    sfi(n);
    S s;
    map<S,int>mp;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        mp[s]=1;
    }
    cout<<6-n<<endl;
    if(mp["purple"]==0) cout<<"Power"<<NL;
    if(mp["green"]==0) cout<<"Time"<<NL;
    if(mp["blue"]==0) cout<<"Space"<<NL;
    if(mp["orange"]==0) cout<<"Soul"<<NL;
    if(mp["red"]==0) cout<<"Reality"<<NL;
    if(mp["yellow"]==0) cout<<"Mind"<<NL;
}
