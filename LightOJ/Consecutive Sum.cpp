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
    trieNode * child[2];
    int cnt;

    trieNode()
    {
        cnt = 0;
        child[0] = NULL;
        child[1] = NULL;
    }
};

trieNode * root;

void insert(int n)
{
    trieNode * curr = root;
    bitset <32> b(n);
    string all_bits = b.to_string();
    For(i,0,sz(all_bits)-1)
    {
        int idx = all_bits[i] - '0';
        if(curr->child[idx]==NULL) curr->child[idx] = new trieNode();
        curr->child[idx]->cnt++;
        curr = curr->child[idx];
    }
}

int searchMax(int n)
{

    int maxi = 0;
    trieNode * curr = root;
    bitset <32> b(n);
    string all_bits = b.to_string();
    For(i,0,sz(all_bits)-1)
    {
        int idx = all_bits[i] - '0';
        if(idx == 0 and curr->child[1])
        {
            maxi += pow(2,(31-i));
            curr = curr->child[1];
        }
        else if(idx == 0 and curr->child[0]) curr = curr->child[0];
        else if(idx == 1 and curr->child[0])
        {
            maxi += pow(2,(31-i));
            curr = curr->child[0];
        }
        else if(idx == 1 and curr->child[1]) curr = curr->child[1];
    }
    return maxi;
}

int searchMin(int n)
{

    int mini = 0;
    trieNode * curr = root;
    bitset <32> b(n);
    string all_bits = b.to_string();
    For(i,0,sz(all_bits)-1)
    {
        int idx = all_bits[i] - '0';
        if(idx == 0 and curr->child[0]) curr = curr->child[0];
        else if(idx == 0 and curr->child[1])
        {
            mini += pow(2,(31-i));
            curr = curr->child[1];
        }
        else if(idx == 1 and curr->child[1]) curr = curr->child[1];
        else if(idx == 1 and curr->child[0])
        {
            mini += pow(2,(31-i));
            curr = curr->child[0];
        }
    }
    return mini;
}

void remove(trieNode * curr, string str, int pos)
{
    if(pos==sz(str)) return;
    int idx = str[pos] - '0';
    remove(curr->child[idx], str, pos+1);
    curr->child[idx]->cnt--;
    if(curr->child[idx]->cnt==0)
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
        vector <int> vec(n+1, 0);
        insert(vec[0]);
        For(i,1,n)
        {
            sfi(vec[i]);
            vec[i] ^= vec[i-1];
            insert(vec[i]);
        }

        int ansMaxi = NINF, ansMini = PINF;
        For(i,1,n)
        {
            bitset <32> b(vec[i]);
            string str = b.to_string();
            remove(root,str,0);
            ansMaxi = max(ansMaxi, searchMax(vec[i]));
            ansMini = min(ansMini, searchMin(vec[i]));
        }

        printf("Case %d: %d %d\n",tt, ansMaxi, ansMini);
    }

//    main();
}

/*

2
5
6 8 2 4 2
5
3 8 2 6 5


*/


