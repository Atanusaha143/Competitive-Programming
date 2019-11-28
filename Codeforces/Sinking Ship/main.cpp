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
    LL n;
    cin>>n;
    S name,pos;
    S rat[n],woman_child[n],man[n],captain[1];
    LL r=0,w_c=0,m=0,cp=0;
    for(int i=0; i<n; i++)
    {
        cin>>name;
        cin>>pos;
        if(pos=="rat")
        {
            rat[r]=name; r++;
        }
        else if(pos=="woman")
        {
            woman_child[w_c]=name; w_c++;
        }
        else if(pos=="child")
        {
            woman_child[w_c]=name; w_c++;
        }
        else if(pos=="man")
        {
            man[m]=name; m++;
        }
        else
        {
            captain[cp]=name;
        }
    }

    for(int i=0; i<r; i++) cout<<rat[i]<<endl;
    for(int i=0; i<w_c; i++) cout<<woman_child[i]<<endl;
    for(int i=0; i<m; i++) cout<<man[i]<<endl;
    cout<<captain[0];
return 0;
}
