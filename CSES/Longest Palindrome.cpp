#include <bits/stdc++.h>
using namespace std;

#define NL              '\n'
#define PINF            INT_MAX
#define NINF            INT_MIN
#define sz(x)           x.size()
#define PB              push_back
#define MP              make_pair
#define asort(x)        sort(all(x));
#define PI              (2.0*acos(0.0))
#define all(x)          x.begin(),x.end()
#define Now             cerr<<"Here"<<endl;
#define For(i, j, k)    for(int i = j; i <= k; i++)
#define Rof(i, j, k)    for(int i = j; i >= k; i--)
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;

#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL  my_rand(LL l, LL r) { return uniform_int_distribution<LL>(l, r) (rng); }

#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
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

///---------------------------------------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------------------------

const int N = 1e6 + 10;
const int MOD = 1000000007;

struct manacher{

    vector<int>p;
    void build(string &s){ /// assuming that the string is not preprocessed
        string t;
        for(auto v:s){
            t.push_back('#');
            t.push_back(v);
        }
        t.push_back('#');
        s=t;
        run_manacher(t);
    }
    void run_manacher(string s){
        int n = s.length();
        p.assign(n,1);
        int l=1,r=1;
        for(int i=1; i<n; i++){
            p[i] = max(0,min(r-i,p[l+(r-i)]));
            while(i-p[i]>=0 and i+p[i]<n and s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }
    int getLongest(int center, bool odd){
        int pos = (2*center)+1;
        if(!odd) pos++;
        return p[pos]-1;
    }
    bool rangeQuery(int l, int r){
        int cur_len = (r-l)+1;
        int cur_pal_len = getLongest((l+r)/2,(l%2)==(r%2));
        return cur_len<=cur_pal_len;
    }

} m;

string s;

void solve(int casenum)
{
    cin>>s;
    string temp=s;
    m.build(s);
    vector<int>p=m.p;
    int maxi=0,pos=0;
    for(int i=0; i<sz(p); i++)
    {
        if(p[i]>maxi)
        {
            maxi=p[i];
            pos=i;
        }
    }
    
    int l=max(0,pos-maxi+1);
    int r=min((int)sz(p),pos+maxi-1);
    for(int i=l;i<=r; i++)
    {
        if(s[i]!='#') cout<<s[i];
    }
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
//    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*
https://cses.fi/problemset/task/1111/
*/
