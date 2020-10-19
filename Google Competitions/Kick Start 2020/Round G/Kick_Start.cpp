#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define sz(x) x.size()
#define INF LONG_MAX
#define IINF LLONG_MAX
#define PI (2.0*acos(0.0))

#define sfi(x) scanf("%d",&x)
#define sfi2(x,y) scanf("%d %d",&x,&y)
#define sfi3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sfl(x) scanf("%lld",&x)
#define sfl2(x,y) scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x) scanf("%lf",&x);
#define sfd2(x,y) scanf("%lf %lf",&x,&y);

#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(a,min3(b,c,d))

#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define For(i, j, k) for(int i = j; i <= k; i++)
#define Rof(i, j, k) for(int i = j; i >= k; i--)
#define all(x) x.begin(),x.end()
#define asort(x) sort(all(x));
#define dsort(x) sort(all(x), greater<int>())
#define unq(x) x.erase(unique(x.begin(),x.end()),x.end())

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

LL gcd(LL a,LL b) { return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a,LL b) { return (a/gcd(a,b))*b; }


int main()
{
    int t; sfi(t); For(tt,1,t){

        string str;
        cin>>str;
        int n = sz(str);
        int first = 0, second = 0, start= 0;
        For(i,0,n-1)
        {
            if(str[i]=='K' and str[i+1]=='I' and str[i+2]=='C' and str[i+3]=='K')
            {
                first = i;
                break;
            }
        }

        Rof(i,n-1,0)
        {
            if(str[i]=='T' and str[i-1]=='R' and str[i-2]=='A' and str[i-3]=='T' and str[i-4]=='S')
            {
                second = i;
                break;
            }
        }

        printf("Case #%d: ", tt);
        if(first < second)
        {
            int count = 0;
            For(i,first,second)
            {
                if(str[i]=='K' and str[i+1]=='I' and str[i+2]=='C' and str[i+3]=='K')
                {
                    For(j,i+4,second)
                    {
                        if(str[j]=='S' and str[j+1]=='T' and str[j+2]=='A' and str[j+3]=='R' and str[j+4]=='T')
                        count++;
                    }
                }
            }
            printf("%d\n", count);
        }
        else printf("0\n");

    }
//    main();
}

