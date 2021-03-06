#include<bits/stdc++.h>
using namespace std;

#define NL '\n'
#define C char
#define D double
#define F float
#define S string

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

#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(a,min3(b,c,d))

#define pb push_back
#define mp(x,y) make_pair(x,y)
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

LL gcd(LL a,LL b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}

LL bigmod(LL base, LL power, LL mod)
{
    if(power==0) return 1;
    else if(power%2==1)
    {
        LL value1 = base % mod; LL value2 = (bigmod(base,power-1,mod))%mod;
        return (value1*value2)%mod;
    }
    else
    {
        LL value1 = (bigmod(base,power/2,mod))%mod;
        return (value1*value1)%mod;
    }
}

bool sortedNaki (int arr[],int n)
{
    for(int i=0; i<n-1; i++)
        if(arr[i]>arr[i+1])
            return true;
    return false;
}

int main()
{
    //IOS;

    int n;
    sfi(n);

    int arr[n];
    for(int i=0; i<n; i++) sfi(arr[i]);

    bool sorted = sortedNaki(arr,n);

    if(!sorted)
    {
        printf("yes\n");
        printf("1 1");
    }

    else
    {
        int left = 0;
        for(int i=0; i<n-1; i++)
            if(arr[i]>arr[i+1])
            {
                left = i;
                break;
            }

        int right = 0;
        for(int i=n-1; i>0; i--)
        {
            if(arr[i]<arr[i-1])
            {
                right = i;
                break;
            }
        }

        //cout<<left<<right;

        int dist = right - left;
        int lefti = left, righti = right;
        for(int i=0; i<ceil(dist/2.00); i++)
        {
            int temp = arr[lefti];
            arr[lefti] = arr[righti];
            arr[righti] = temp;
            lefti++;
            righti--;
        }

        bool thikNai = sortedNaki(arr,n);
        if(thikNai) printf("no");
        else
        {
            printf("yes\n");
            printf("%d %d", left+1, right+1);
        }
    }
}
