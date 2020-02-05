#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
#define sz(x) x.size()
#define INF LONG_LONG_MAX
#define PI (2.0*acos(0.0))
#define sfi(x) scanf("%d",&x)
#define sfi2(x,y) scanf("%d %d",&x,&y)
#define sfi3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sfl(x) scanf("%lld",&x)
#define sfl2(x,y) scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x) scanf("%lf",&x);
#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define mem(ara,val) memset(ara,val,sizeof(ara))
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

/*LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}*/


int main()
{
    int t;
    sfi(t);
    while(t--)
    {
        int n;
        sfi(n);

        vector < pair<int,int> > vec;
        vector < pair<int,int> > :: iterator it;

        int a,b;
        for(int i=0; i<n; i++)
            {
                sfi2(a,b);
                vec.push_back(make_pair(a,b));
            }

        sort(vec.begin(),vec.end());

        S s = "";
        int x = 0, y = 0, dif=0;
        bool flag = false;
        for(int i=0; i<n; i++)
        {
            if(vec[i].first >= x && vec[i].second >= y)
            {
                dif = vec[i].first - x;
                for(int i=1; i<=dif; i++) s += 'R';
                x = vec[i].first;

                dif = vec[i].second - y;
                for(int i=1; i<=dif; i++) s += 'U';
                y = vec[i].second;
            }
            else
            {
                flag = true;
                break;
            }
        }

        if(!flag)
            {
                cout<<"YES"<<NL;
                cout<<s<<NL;
            }
        else
            cout<<"NO"<<NL;

    }

}
