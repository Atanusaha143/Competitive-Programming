#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define endl              '\n'
#define sz(x)           x.size()
#define PINF            INT_MAX
#define NINF            INT_MIN
#define PI              (2.0*acos(0.0))
#define PB              push_back
#define MP              make_pair
#define all(x)          x.begin(),x.end()
#define asort(x)        sort(all(x));
#define dsort(x)        sort(all(x), greater<int>())
#define unq(x)          x.erase(unique(x.begin(),x.end()),x.end())
#define popcountl       __builtin_popcountll
#define popcount        __builtin_popcount
#define now             cout<<"Here"<<endl;
#define mem(ara,val)    memset(ara,val,sizeof(ara))
#define READ            freopen("input.txt","r",stdin)
#define WRITE           freopen("output.txt","w",stdout)
#define IOS             ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// *find_by_order = value of an index, order_of_key = index of a value where it should be
//typedef tree<PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }

LL gcd(LL a, LL b) { return b==0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

//LL power_mod(LL base, LL power, LL mod){
//    if(power==0) return 1LL;
//    else if(power%2LL == 1){
//        LL p1 = base % mod; LL p2 = (power_mod(base,power-1,mod))%mod;
//        p1 = (LL)(p1*p2); return p1%mod;
//    }
//    else if(power%2LL == 0){
//        LL p1 = (power_mod(base,power/2LL,mod))%mod; p1 = (LL)(p1*p1);
//        return p1%mod;
//    }
//}

//LL original_power(LL base, LL power){
//    if(power==0) return 1LL;
//    else if(power%2LL == 1){
//        LL p1 = base; LL p2 = (original_power(base,power-1));
//        p1 = (LL)(p1*p2); return p1;
//    }
//    else if(power%2LL == 0){
//        LL p1 = (original_power(base,power/2LL)); p1 = (LL)(p1*p1);
//        return p1;
//    }
//}

//// Grid direction array [4]
//int X[4]= {0,0,-1,1};
//int Y[4]= {1,-1,0,0};
// Grid direction array [8]
//int X8[8]= {0,0,1,-1,-1,1,1,-1};
//int Y8[8]= {1,-1,0,0,-1,-1,1,1};
//// Knight Direction Array
//int KX[8] = {1,1,2,2,-1,-1,-2,-2};
//int KY[8] = {2,-2,1,-1,2,-2,1,-1};

///------------------------------------------------------------------------------------------------------

const int N = 2e5 + 10;
const int MOD = 1000000007;

const int MAXN=5005;
struct DoubleHash{
    LL P[2][MAXN];
    LL H[2][MAXN];
    LL R[2][MAXN];
    LL base[2];
    LL mod[2];
    void gen(){
        base[0] = 1949313259LL;
        base[1] = 1997293877LL;
        mod[0]  = 2091573227LL;
        mod[1]  = 2117566807LL;
        for(int j=0;j<2;j++){
            for(int i=0;i<MAXN;i++){
                H[j][i]=R[j][i] = 0LL;
                P[j][i] = 1LL;
            }
        }
        for(int j=0;j<2;j++){
            for(int i=1;i<MAXN;i++){
                P[j][i] = (P[j][i-1] * base[j])%mod[j];
            }
        }
    }
    void make_hash(string &arr){
        int len = arr.size();
        for(int j=0;j<2;j++){
            for (LL i = 1; i <= len; i++)H[j][i] = (H[j][i - 1] * base[j] + arr[i - 1] + 1007) % mod[j];
            for (LL i = len; i >= 1; i--)R[j][i] = (R[j][i + 1] * base[j] + arr[i - 1] + 1007) % mod[j];
        }
    }
    inline LL range_hash(int l,int r,int idx){
        LL hashval = H[idx][r + 1] - ((long long)P[idx][r - l + 1] * H[idx][l] % mod[idx]);
        return (hashval < 0 ? hashval + mod[idx] : hashval);
    }
    inline LL reverse_hash(int l,int r,int idx){
        LL hashval = R[idx][l + 1] - ((long long)P[idx][r - l + 1] * R[idx][r + 2] % mod[idx]);
        return (hashval < 0 ? hashval + mod[idx] : hashval);
    }
    inline LL range_dhash(int l,int r){
        LL x = range_hash(l,r,0);
        return (x<<32)^range_hash(l,r,1);
    }
    inline LL reverse_dhash(int l,int r){
        LL x = reverse_hash(l,r,0);
        return (x<<32)^reverse_hash(l,r,1);
    }
} DH[3];

void solve(int casenum)
{

    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    DH[0].gen();
    DH[1].gen();
    DH[2].gen();
    DH[0].make_hash(s1);
    DH[1].make_hash(s2);
    DH[2].make_hash(s3);

    int l = 1, r = min( {(int)s1.size(), (int)s2.size(), (int)s3.size()} ), mid, ans = 0;
    while(l <= r)
    {
        mid = (l + r) / 2;
        map <LL,bool> mp1, mp2, mp3;
        for(int i=0; (i+mid)-1<s1.size(); i++)
        {
            LL x = DH[0].range_dhash(i,(i+mid)-1);
            mp1[x] = true;
        }
        for(int i=0; (i+mid)-1<s2.size(); i++)
        {
            LL x = DH[1].range_dhash(i,(i+mid)-1);
            mp2[x] = true;
        }
        for(int i=0; (i+mid)-1<s3.size(); i++)
        {
            LL x = DH[2].range_dhash(i,(i+mid)-1);
            mp3[x] = true;
        }

        bool cur_ans = false;
        for(auto x : mp1)
        {
            if((mp2.find(x.first) != mp2.end()) and (mp3.find(x.first) != mp3.end()))
            {
                cur_ans = true;
                break;
            }
        }
        if(cur_ans)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout<<"Case "<<casenum<<": "<<ans<<endl;

}

int main()
{
    IOS;

//    READ;
//    WRITE;

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/aladdin-and-the-magical-lamp

Sol : Fix a length via binary search and valid that. Keep all the kth length substring hash for
each string and search if a hash value occurs in other two.

*/

