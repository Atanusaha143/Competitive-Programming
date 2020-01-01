  // https://codeforces.com/contest/855/problem/A
    #include<bits/stdc++.h>
    using namespace std;

    #define NL '\n'
    #define C char
    #define D double
    #define F float
    #define S string
    #define PI (2.0*acos(0.0))
    #define sfi(x) scanf("%d",&x)
    #define sfl(x) scanf("%I64d",&x)
    #define sfd(x) scanf("%lf",&x)
    #define sfs(x) scanf("%s",x)
    #define READ freopen("input.txt","r",stdin)
    #define WRITE freopen("output.txt","w",stdout)
    #define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    typedef long long LL;
    typedef unsigned long long ULL;
    typedef long double LD;

    int main()
    {
        LL t;
        cin>>t;
        S s;
        map<S,LL>mp;
        for(int i=0; i<t; i++)
         {
          cin>>s;
          mp[s]++;
          if(mp[s]>1) cout<<"YES"<<NL;
          else cout<<"NO"<<NL;
         }
        return 0;
    }
