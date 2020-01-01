#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string
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
        LL count=1;
        S s;
        cin>>s;
        S ss = "";
        LL sz = s.size();
        LL arr[sz],k=0;;
        for(int i=0; i<sz; i++)
        {
            if(s[i]!=s[i+1])
            {
                ss = ss + s[i];
                arr[k] = count;
                k++;
                count = 1;
            }
            else count++;
        }
        LL ssz = ss.size();
        for(int i=0; i<k; i++)
        {
            LL digit_size=0;
            LL check = arr[i];
            while(check!=0)
            {
                check/=10;
                digit_size++;
            }
            arr[i] = digit_size;
        }

        LL total_digit_size=0;
        for(int i=0; i<k; i++) total_digit_size+=arr[i];
        LL new_string_size = ssz + total_digit_size;

        if(new_string_size<sz) cout<<"YES"<<NL;
        else cout<<"NO"<<NL;
    }
}
