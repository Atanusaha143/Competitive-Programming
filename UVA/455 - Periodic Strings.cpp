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

const int N = 2e6 + 10;
const int MOD = 1000000007;

int lps[N];

int buildKMP(string &text, int len)
{
    int cnt = 0;
    int n = text.size();
    for(int i=1; i<n; i++)
    {
        int j = lps[i-1];
        while(j > 0 and text[i] != text[j]) j = lps[j-1];
        if(text[i] == text[j]) j++;
        lps[i] = j;
        if(j == len) cnt++;
    }
    return cnt;
}

void solve(int casenum)
{
    string text;
    cin>>text;
    int text_len = text.size();
    int ans = 0;
    string cur_ans;
    for(int i=0; i<text_len; i++)
    {
        cur_ans.PB(text[i]);
        if(text_len % (i+1) == 0)
        {
            string news = cur_ans + '#' + text;
            int x = buildKMP(news,cur_ans.size()); /// gives how many times the cur_ans occurs in original string
            if(lps[news.size()-1]*x == text.size()) /// if the answer if correct, then the (matching prefix size * cnt) should be same as text size
            {
                ans = i+1;
                break;
            }
        }
    }
    cout<<ans<<endl;

}

int main()
{
    IOS;

//    READ;
//    WRITE;

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        cin.ignore();
        solve(tt);
        if(tt < t) cout<<endl;
    }

    return 0;
}

/*

https://onlinejudge.org/external/4/455.pdf

*/
