#include <bits/stdc++.h>
using namespace std;

#define NL '\n'
#define sz(x) x.size()
#define PINF INT_MAX
#define NINF INT_MIN
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
#define now cout<<"Here"<<NL

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
bool compare(string &str1, string &str2) { return str1.size() > str2.size(); }

int dx[] = {0,1,0,-1}; // direction array
int dy[] = {-1,0,1,0};
int kx[] = {1,2,2,1,-1,-2,-2,-1}; // knights move
int ky[] = {2,1,-1,-2,-2,-1,1,2};

LL fun(LL num)
{
    LL l = 0, r = 1000000000, ans = 0;
    while(l<=r)
    {
        LL mid = l + (r-l) / 2LL;
        LL total = (mid*(mid+1))/2LL;
        if(total <= num)
        {
            ans = max(ans,mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

int main()
{

    int t; sfi(t); For(tt,1,t){

        LL num;
        sfl(num);
        printf("%lld\n", fun(num));

    }

    //main();
}

