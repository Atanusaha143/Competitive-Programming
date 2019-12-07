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
        LL count=0;
        S s;
        cin>>s;
        LL x = s.size();
        for(int i=0; i<x; i++)
        {
            if(s[i]==s[i+1] && s[i]!='?' && s[i+1]!='?')
            {
                count++;
                cout<<"-1\n";
                break;
            }
        }
        if(count==0)
        {
            for(int i=0; i<x; i++)
            {
                if(s[i]=='?')
                {
                    if(s[i-1]!='a' && s[i+1]!='a') s[i]='a';
                else if(s[i-1]!='b' && s[i+1]!='b') s[i]='b';
                else if(s[i-1]!='c' && s[i+1]!='c') s[i]='c';
                }
            }
            cout<<s<<endl;
        }
    }
}
