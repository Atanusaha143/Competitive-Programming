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
        string s;
        cin>>s;
        ll x = s.size();
        ll cnt[30];
        memset(cnt,0,sizeof(cnt));

        for(int i=0; i<x; i++)
        {
            if(s[i]==s[i+1]) i++;
            else cnt[s[i]-'a']++;
        }
        for(int i=0; i<26; i++)
        {
            if(cnt[i]>0) cout<<char('a'+i);
        }
        cout<<endl;
    }
    return 0;
}
