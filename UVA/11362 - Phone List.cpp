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

int dx[] = {0,1,0,-1}; // direction array
int dy[] = {-1,0,1,0};
int kx[] = {1,2,2,1,-1,-2,-2,-1}; // knights move
int ky[] = {2,1,-1,-2,-2,-1,1,2};

bool check = false;
struct trieNode
{
    trieNode * child[10];
    bool isLast;
    trieNode()
    {
        isLast = false;
        For(i,0,9) child[i] = NULL;
    }
};

trieNode * root;

void insert(const string &str)
{
    trieNode * curr = root;
    int len = sz(str);
    For(i,0,len-1)
    {
        int idx = str[i] - '0';
        if(curr->child[idx]==NULL) curr->child[idx] = new trieNode();
        curr = curr->child[idx];
    }
    curr->isLast = true;
}
void search(const string &str)
{
    trieNode * curr = root;
    int len = sz(str);
    For(i,0,len-1)
    {
        int idx = str[i] - '0';
        curr = curr->child[idx];
        if(curr->isLast==true and i!=len-1) { check = true; return; }
    }
}

int main()
{

    int t; sfi(t); For(tt,1,t){

        root = new trieNode();
        check = false;
        int n;
        sfi(n);
        vector <string> vec(n);
        For(i,0,n-1)
        {
            string str;
            cin>>vec[i];
            insert(vec[i]);
        }

        For(i,0,n-1)
        {
            search(vec[i]);
            if(check) break;
        }
        if(check) printf("NO\n");
        else printf("YES\n");

    }

//    main();
}

/*

3
3
911
97625999
91125426
5
113
12340
123440
12345
98346
2
9111
91

*/
