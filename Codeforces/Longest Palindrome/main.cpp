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

/*bool pal (S s)
{
    bool flag = true;
    for(int i=0; i<sz(s); i++)
    {
        if(s[i]!=s[sz(s)-i-1])
        {
            flag = false;
            break;
        }
    }
    if(flag) return true;
    else return false;
}*/

int main()
{
    int n,m;
    sfi2(n,m);

    vector <S> palv;

    S arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        S s = arr[i];

        bool flag = false;
        for(int i=0; i<sz(s); i++)
        {
            if(s[i]!=s[sz(s)-i-1])
            {
                flag = true;
                break;
            }
        }
        if(!flag) palv.push_back(s);
    }

    vector <S> first;
    vector <S> last;

    for(int i=0; i<n-1; i++)
    {
        S rev = arr[i];
        reverse(rev.begin(),rev.end());

        for(int j=i+1; j<n; j++)
        {
           if(arr[j]==rev)
           {
               first.push_back(arr[i]);
               last.push_back(arr[j]);
           }
        }
    }

    S pal = "";
    if(sz(first)!=0)
    for(int i=0; i<sz(first); i++)
        pal += first[i];

    if(sz(palv)!=0)
    {
        for(int i=0; i<1; i++)
        pal += palv[i];
    }

    if(sz(last)!=0)
    for(int i=sz(last)-1; i>=0; i--)
        pal += last[i];

    if(sz(pal)!=0)
        cout<<sz(pal)<<NL<<pal;
        else cout<<0<<NL;

}
