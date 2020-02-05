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
}*/
/*LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}*/
int check(S s1, C cp_s3)
{
  for(int i=0; i<26; i++)
  {
      if(s1[i]==cp_s3)
            return i;
  }
}
int main()
{
    S s1,s2,s3;
    cin>>s1>>s2>>s3;
    S cp_s3 = "";
    for(int i=0; i<sz(s3); i++)
    {
        if(s3[i]>='A' && s3[i]<='Z')
        cp_s3+=s3[i]+32;
        else
        cp_s3+=s3[i];
    }

    S ex_s = "";
    for(int i=0; i<sz(s3); i++)
    {
        int idx = check(s1,cp_s3[i]);
            if(s3[i]>='A' && s3[i]<='Z')
                {
                    ex_s+=s2[idx]-32;
                }
            else if (s3[i]>='0' && s3[i]<='9')
                {
                    ex_s+=s3[i];
                }
            else
                {
                    ex_s+=s2[idx];
                }
    }
    cout<<ex_s;
}
