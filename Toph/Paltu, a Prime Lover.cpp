#include <bits/stdc++.h>
using namespace std;

#define NL              '\n'
#define sz(x)           x.size()
#define PINF            INT_MAX
#define NINF            INT_MIN
#define PI              (2.0*acos(0.0))

#define sfi(x)          scanf("%d",&x)
#define sfi2(x,y)       scanf("%d %d",&x,&y)
#define sfi3(x,y,z)     scanf("%d %d %d",&x,&y,&z)
#define sfl(x)          scanf("%lld",&x)
#define sfl2(x,y)       scanf("%lld %lld",&x,&y)
#define sfl3(x,y,z)     scanf("%lld %lld %lld",&x,&y,&z)
#define sfd(x)          scanf("%lf",&x);
#define sfd2(x,y)       scanf("%lf %lf",&x,&y);

#define max3(a,b,c)     max(a,max(b,c))
#define max4(a,b,c,d)   max(max3(a,b,c),d)
#define min3(a,b,c)     min(a,min(b,c))
#define min4(a,b,c,d)   min(a,min3(b,c,d))

#define PB              push_back
#define MP              make_pair
#define For(i, j, k)    for(int i = j; i <= k; i++)
#define Rof(i, j, k)    for(int i = j; i >= k; i--)
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define now             cout<<"Here"<<NL;

#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define READ            freopen("input.txt","r",stdin)
#define WRITE           freopen("output.txt","w",stdout)
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

LL gcd(LL a,LL b) { return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a,LL b) { return (a/gcd(a,b))*b; }

LL power_mod(LL base, LL power, LL mod)
{
    if(power==0) return 1LL;
    else if(power%2LL == 1)
    {
        LL p1 = base % mod;
        LL p2 = (power_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2LL == 0)
    {
        LL p1 = (power_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}

// Grid direction array [4]
int X[4]= {0,0,-1,1};
int Y[4]= {1,-1,0,0};
// Grid direction array [8]
int X8[8]= {0,0,1,-1,-1,1,1,-1};
int Y8[8]= {1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

inline bool checkBit(int N, int pos){return (bool)(N & (1 << pos));}
inline int setBit(int N, int pos) { return N = N | (1 << pos); }

const int N = 1e5 + 10;
//const LL MOD = 1000000007;
int n,q;
LL arr[N], treeMin[4*N], treeMax[4*N];

const int maxn = 1e8 + 10;
const int primeLimit = 1e7;
int status[(maxn/32)+2];
int primes[primeLimit], cnt;

void bitsieve()
{
     int sqrtN = int(sqrt(maxn)), N = 1e8 + 10;
     for(int i=3; i <= sqrtN; i+=2)
     {
		 if(checkBit(status[i>>5],i&31)==0)
		 {
	 		 for(int j=i*i; j<=N; j+=(i<<1))
			 {
				 status[j>>5] = setBit(status[j>>5],j&31);
	 		 }
		 }
	 }

     cnt = 1;
	 primes[cnt++] = 2;
	 for(int i=3;i<=N;i+=2)
		 if(checkBit(status[i>>5],i&31)==0)
            primes[cnt++] = i;

}

void build1(LL node, LL b, LL e)
{
    if(b==e)
    {
        treeMin[node] = arr[b];
        return;
    }

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    build1(left,b,mid);
    build1(right,mid+1,e);
    treeMin[node] = min(treeMin[left],treeMin[right]);
}

void build2(LL node, LL b, LL e)
{
    if(b==e)
    {
        treeMax[node] = arr[b];
        return;
    }

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    build2(left,b,mid);
    build2(right,mid+1,e);
    treeMax[node] = max(treeMax[left],treeMax[right]);
}

void update1(LL node, LL b, LL e, LL i, LL value)
{
    if(b > i or e < i) return;
    if(b == e and b == i)
    {
        treeMin[node] = value;
        return;
    }

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    if(mid >= i) update1(left,b,mid,i,value);
    else update1(right,mid+1,e,i,value);

    treeMin[node] = min(treeMin[left],treeMin[right]);
}

void update2(LL node, LL b, LL e, LL i, LL value)
{
    if(b > i or e < i) return;
    if(b == e and b == i)
    {
        treeMax[node] = value;
        return;
    }

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    if(mid >= i) update2(left,b,mid,i,value);
    else update2(right,mid+1,e,i,value);

    treeMax[node] = max(treeMax[left],treeMax[right]);
}

LL query1(LL node, LL b, LL e, LL i, LL j)
{
    if(b > j or e < i) return 1e14;
    if(b >= i and e <= j) return treeMin[node];

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    LL p = query1(left,b,mid,i,j);
    LL q = query1(right,mid+1,e,i,j);

    LL mini = min(p,q);
    return mini;
}

LL query2(LL node, LL b, LL e, LL i, LL j)
{
    if(b > j or e < i) return 0;
    if(b >= i and e <= j) return treeMax[node];

    LL mid = (b+e) / 2;
    LL left = node * 2;
    LL right = left + 1;

    LL p = query2(left,b,mid,i,j);
    LL q = query2(right,mid+1,e,i,j);

    LL maxi = max(p,q);
    return maxi;
}

int getMinIdx(int l, int r, int mini)
{
    int mid, miniIdx = -1;
    while(l<=r)
    {
        mid = (l + r) / 2;
        if(primes[mid] >= mini)
        {
            miniIdx = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return miniIdx;
}

int getMaxIdx(int l, int r, int maxi)
{
    int mid, maxIdx = -1;
    while(l<=r)
    {
        mid = (l + r) / 2;
        if(primes[mid] <= maxi)
        {
            maxIdx = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return maxIdx;
}

int main()
{
//    int t; sfi(t); For(tt,1,t){}

    bitsieve();

    sfi2(n,q);
    For(i,1,n) sfi(arr[i]);

    build1(1LL,1LL,N);
    build2(1LL,1LL,N);

    while(q--)
    {
        int k;
        sfi(k);

        if(k == 1)
        {
            int pos, val;
            sfi2(pos,val);
            update1(1LL,1LL,N,pos,val);
            update2(1LL,1LL,N,pos,val);
        }
        else
        {
            int i, j;
            sfi2(i,j);
            int mini = query1(1LL,1LL,N,i,j);
            int maxi = query2(1LL,1LL,N,i,j);

            int miniIdx = getMinIdx(1,cnt,mini);
            int maxiIdx = getMaxIdx(1,cnt,maxi);

            int ans = (maxiIdx - miniIdx) + 1;

            printf("%d\n", ans);

        }
    }


//    main();
}

/*

*/
