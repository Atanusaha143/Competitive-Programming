#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,j,count=0;
        cin>>n;
        string a,b;
        cin>>a>>b;
        for(i=0; i<n; i++)
        {
          if(a[i]!=b[i])
          {
              break;
          }
        }
        for(j=n-1; j>=0; j--)
        {
            if(a[j]!=b[j])
            {
                char x = a[i];
                a[i] = b[j];
                b[j] = x;
                break;
            }
        }

        for(int i=0; i<n; i++)
        {
            if(a[i]==b[i]) count++;
        }
        if(count==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}
