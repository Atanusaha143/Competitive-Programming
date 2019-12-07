#include<bits/stdc++.h>
#define C char
#define D double
#define F float
#define LL long long
#define ULLI unsigned long long int
#define LLI long long int
#define LLD long long double
#define LD long double
#define S string
#define PI (2.0*acos(0.0))
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    LL t;
    cin>>t;
    while(t--)
    {
        LL n,indx=0;
        cin>>n;
        S s;
        cin>>s;
        if(n<11) cout<<"NO\n";
        else if(s[0]=='8') cout<<"YES\n";
        else
        {
            for(int i=0; i<n; i++)
            {
                if(s[i]=='8')
                {
                    indx = i;
                    break;
                }
            }
            if(indx==0) cout<<"NO\n";
            else if(n-indx>=11) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
