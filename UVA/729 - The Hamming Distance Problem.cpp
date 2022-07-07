#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, h;
vector <int> vec;
void fun(int pos, int cnt, int num)
{
    if(pos >= n)
    {
        if(cnt == h)
        {
            vec.push_back(num);
        }
        return;
    }
    num = num | 1 << pos;
    fun(pos+1,cnt+1,num);
    num = num ^ 1 << pos;
    fun(pos+1,cnt,num);
}

void solve()
{
    cin>>n>>h;
    fun(0,0,0);
    if(vec.size()) sort(vec.begin(),vec.end());
    for(auto x : vec)
    {
        for(int i=n-1; i>=0; i--)
        {
            bool cur = x & (1 << i);
            cout<<cur;
        }
        cout<<endl;
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tt;
    cin>>tt;
    for(int i=1; i<=tt; i++)
    {
        solve();
        vec.clear();
        if(i != tt) cout<<endl;
    }
}

/*
https://onlinejudge.org/external/7/729.pdf
*/

