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

int arr[N];

void solve(int casenum)
{

    int n;
    cin>>n;
    int out_door = 0;
    LL total = 0;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(arr[i] > 0) out_door++;

        if(arr[i] < 0) total += (-1*arr[i]);
        else total += arr[i];
    }

    cout<<"Case "<<casenum<<": ";

    if(out_door == 0) cout<<"inf"<<endl;
    else
    {
        int g = gcd(total,out_door);
        total /= g;
        out_door /= g;
        cout<<total<<"/"<<out_door<<endl;
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
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        solve(tt);
    }

    return 0;
}

/*

Link : https://lightoj.com/problem/a-dangerous-maze

Sol:
By the definition of Mathematical Expectation,
If P(i) represents probability of choosing door i and T(i) represents time to get out of the maze if we choose door i,
then for n number of doors,
Mathematical Expectation,
E = P(1)*T(1) + P(2)*T(2) + P(3)*T(3) + ...... + P(n)*T(n)

Let's begin with analyzing the 3rd test of the sample test case. The 3rd test case is -

3
3 -6 -9

Here, we are given 3 doors. And we can only get out of the maze by the first door with a cost of 3 minutes. 
Where, the 2nd and 3rd door would return us to the same position costing 6 minutes and 9 minutes respectively.
Let's assume the final expected time be E, what is our answer.
So here,
E = P(1)*T(1) + P(2)*T(2) + P(3)*T(3)

Each time we can randomly choose 1 door out of 3 doors and choosing one door is an independent event.
So, probability of choosing any door would be 1/3.
Thus, P(i) = 1/3, for i = 1, 2, 3
Now, we need to calculate T(i) for i = 1, 2, 3

If i = 1 i.e if we choose 1st door it would take us straight out of the maze. So T(1) = 3

If i = 2 i.e if we choose 2nd door it would take 6 minutes to return us to the same position!
So, sadly we would have to start the whole process once again. As we assumed before that the final expected time is E, 
therefore we can safely say that for starting the whole process once again we will need E minutes more!
Thus time to get out of the maze if we choose 2nd gate
T(2) = Time to return to the same position + Expected time to get out of the maze for starting the process from beginning. 
Therefore, T(2) = 6 + E
Similiarly, if i = 3, T(3) = 9 + E

So, finally,
E = (1/3)*3 + (1/3)*(6 + E) + (1/3)*(9 + E)
E = (1/3)*(3 + 6 + 9) + (1/3)*(E + E)
(1/3)*(3*E - 2*E) = (1/3)*(3 + 6 + 9)
E*(3 - 2) = (3 + 6 + 9) (Diving both sides by 1/3)
and, E = (3 + 6 + 9)/(3 - 2) ......... (1)

If we look at equation (1), we can see,
3 + 6 + 9 is the sum of absolute value of time taken by each door.
And, 3 is the number of doors and 2 is the number of reverse doors (doors that returns to the same postion). In other word, (3-2) is the number of doors that can get us out of the maze.

So, now we can have a generalized solution for this problem,
E = (sum of absolute value of the given times) / (number of gates that can take us out of the maze)

As, the output format is p/q, so both the the numbers divded by their GCD will be the ultimate solution.

*/

