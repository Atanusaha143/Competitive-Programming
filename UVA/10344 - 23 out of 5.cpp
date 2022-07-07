#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, arr[6];
vector <int> permutationList;
bool possible;

bool fun(int pos, int sum)
{
    if(pos == n)
    {
        if(sum == 23) return true;
        return false;
    }
    bool val = false;
    val |= fun( pos + 1, sum + permutationList[pos] );
    val |= fun( pos + 1, sum - permutationList[pos] );
    val |= fun( pos + 1, sum * permutationList[pos] );
    return val;
}

int mask;
void generatePermuation()
{
    if((int)permutationList.size() == n)
    {
        bool x = fun(1,permutationList[0]);
        if(x) possible = true;
    }
    for(int i=0; i<n; i++)
    {
        bool taken = (bool) (mask & (1 << i));
        if(taken) continue;
        mask |= (1 << i);
        permutationList.push_back(arr[i]);
        generatePermuation();
        permutationList.pop_back();
        mask ^= (1 << i);
    }
}

int main()
{
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    n = 5;
    while(1)
    {
        bool finish = true;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]) finish = false;
        }
        if(finish) break;
        possible = false;
        generatePermuation();
        if(possible) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
}

/*
https://onlinejudge.org/external/103/10344.pdf
*/

