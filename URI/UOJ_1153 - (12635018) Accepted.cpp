#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,n=1;
    cin>>x;
    for(int i=x; i>=1; i--)
    {
      n=n*i;
    }
    cout<<n<<endl;
    return 0;
}
