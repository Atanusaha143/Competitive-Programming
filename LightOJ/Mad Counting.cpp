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

void solve(int casenum)
{

    int n;
    cin>>n;
    int x;
    map <int,int> mp;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        x++;
        mp[x]++;
    }
    
    LL sum = 0;
    for(auto x : mp)
    {
        int total_freq = x.second;
        int each_team_max = x.first;
        sum += (1LL * (total_freq / each_team_max) * each_team_max);
        if(total_freq % each_team_max)
        {
            sum += each_team_max;
        }
    }
    cout<<"Case "<<casenum<<": "<<sum<<endl;
}

int main()
{
    IOS;

    #ifdef sinbadCP
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/mad-counting

Sol : Let's try to assign a person to a group where the person belong. 
For example the given array is : [ 1, 1, 2, 2, 2, 2 ]
1st person is saying that in his group there are 2 people including him. 
Same statement was given by 2nd person.
Let's name the group 'A'. Then the group will look like:
                                    A
                                   / \
                                  1   2
So according to 1st and 2nd person's statemement there are 2 people in their group.
1st person's statement validation: { 1, 2 } *1st person himself and 2nd person
2nd person's statement validation: { 2, 1 } *2nd person himself and 1st person

3rd person is saying that in his group there are 3 people including him. 
Same statement was given by 4th, 5th and 6th person.
Let's name the group 'B'. Then the group will look like:
                                    B
                                  / | \
                                 3  4  5
So according to 3rd, 4th and 5th person's statemement there are 3 people in their group.
3rd person's statement validation: { 3, 4, 5 } *3rd person himself and 4th and 5th person
4th person's statement validation: { 4, 3, 5 } *4th person himself and 3rd and 5th person
5th person's statement validation: { 5, 3, 4 } *5th person himself and 3rd and 4th person

Here, we can notice that we can't add more people to this group. If we do then it won't
follow the statement given by the people. So, what will happen to the statement of the
6th person as the person was saying the same statement?
For 6th person, we have to make a new group with 3 people according to the statement.
Let's name the group 'C'. Then the group will look like:
                                    C
                                  / | \
                                 6  7  8
So, there are total 8 people according to their statement.

*/