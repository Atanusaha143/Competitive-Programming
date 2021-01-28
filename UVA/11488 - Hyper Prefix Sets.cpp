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

struct trieNode
{
    int count;
    trieNode * child[2];

    trieNode()
    {
        count = 0;
        For(i,0,1) child[i] = NULL;
    }
};

trieNode * root;

int insert(const string &str)
{
    trieNode * curr = root;
    int res = 0;
    For(i,0,sz(str)-1)
    {
        int idx = str[i] - '0';
        if(curr->child[idx]==NULL) { curr->child[idx] = new trieNode(); }
        curr->child[idx]->count++;
        curr = curr->child[idx];
        res = max(res,(curr->count*(i+1)));
    }
    return res;
}

void remove(trieNode * curr, const string &str, int pos)
{
    if(pos==sz(str)) return;
    int idx = str[pos]-'0';
    remove(curr->child[idx], str, pos+1);
    curr->child[idx]->count--;
    if(curr->child[idx]->count==0)
    {
        free(curr->child[idx]);
        curr->child[idx] = NULL;
    }
}

int main()
{

    int t; sfi(t); For(tt,1,t){

        root = new trieNode();

        int n;
        sfi(n);
        vector <string> vec(n);
        int maxi = 0;

        For(i,0,n-1)
        {
            cin>>vec[i];
            maxi = max(maxi,(int)sz(vec[i]));
        }

        int ans = 0;
        For(i,0,n-1)
        {
            int res = insert(vec[i]);
            ans = max3(maxi,res,ans);
        }

        cout<<ans<<NL;

        For(i,0,n-1) remove(root,vec[i],0);
    }

//    main();
}

/*

4
4
0000
0001
10101
010
2
01010010101010101010
11010010101010101010
3
010101010101000010001010
010101010101000010001000
010101010101000010001010
5
01010101010100001010010010100101
01010101010100001010011010101010
00001010101010110101
0001010101011010101
00010101010101001

*/
