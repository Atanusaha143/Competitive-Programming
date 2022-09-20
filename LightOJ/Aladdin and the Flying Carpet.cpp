#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define PI              (2.0*acos(0.0))
#define PB              push_back
#define MP              make_pair
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
#define now             cerr<<"Here"<<endl;
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

///------------------------------------------------------------------------------------------------------------------------

const int N = 1e6 + 10;
const int MOD = 1000000007;

bool prime[N+1];
vector <int> allprimes;

void genPrimes()
{
    int limit = sqrt(N);
    prime[1] = true;
    prime[2] = false;
    for(int i=4; i<=N; i+=2) prime[i] = true;
    for(int i=3; i<=limit; i+=2)
        if(!prime[i])
            for(int j=i*i; j<=N; j+=i*2)
                prime[j] = true;

    for(int i=2; i<N; i++)
        if(!prime[i])
            allprimes.PB(i);
}

struct info {
    LL pf, cntpf;
};

vector <info> primefacts;
vector <LL> divs;

void genDivisors(LL curDiv, int curIdx)
{
    if(curIdx == (int)primefacts.size()) 
    {
        divs.PB(curDiv);
        return;
    }
    for(int i=0; i<=primefacts[curIdx].cntpf; i++) 
    {
        genDivisors(curDiv,curIdx + 1);
        curDiv *= primefacts[curIdx].pf;
    }
}

void findDivisors(LL n)
{
    if((int)divs.size()) divs.clear();
    if((int)primefacts.size()) primefacts.clear();

    for(int i=0; (LL)allprimes[i]*allprimes[i]<=n; i++) 
    {
        if(n%allprimes[i] == 0)
        {
            int cnt = 0;
            while(n%allprimes[i] == 0) 
            {
                n /= allprimes[i];
                cnt++;
            }
            primefacts.push_back({ allprimes[i],cnt });
        }
    }
    if(n > 1) 
    {
        primefacts.push_back({ n,1 });
    }

    LL curDiv = 1;
    int curIdx = 0;
    genDivisors(curDiv,curIdx);
}

int getIdx(LL m)
{
    int l = 0, r = divs.size() - 1, mid, ans = -1;
    while(l <= r)
    {
        mid = l + (r - l) / 2LL;
        if(divs[mid] >= m)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

void solve(int casenum)
{
    LL n, m;
    cin>>n>>m;
    findDivisors(n);
    asort(divs);
    int limit = divs.size() / 2, res = 0;
    int idx = getIdx(m);
    if(idx != -1 and limit - idx >= 0) res = limit - idx;

    cout<<"Case "<<casenum<<": "<<res<<endl;
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    genPrimes();

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/aladdin-and-the-flying-carpet

*/