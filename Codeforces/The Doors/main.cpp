// https://codeforces.com/contest/1143/problem/A

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
        LL t,lcount=0,rcount=0;
        cin>>t;
        LL arr[t+1];
        for(int i=1; i<=t; i++)
        {
            cin>>arr[i];
            if(arr[i]==0) lcount++;
            else rcount++;
        }
        for(int i=1; i<=t; i++)
        {
            if(arr[i]==0)
            {
                lcount--;
                if(lcount==0)
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
            else
            {
                rcount--;
                if(rcount==0)
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
}
