#include<bits/stdc++.h>
#include<iomanip>
#define C char
#define D double
#define S string
#define LL long long
#define ULL unsigned long long
#define LLI long long int
#define LLD long long double
#define LD long double
#define PI (2.0*acos(0.0))
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    IOS;
    READ;
    WRITE;
    int b,g,count=0;
    cin>>b>>g;
    int z = b+g;
    char zarr[z];
    if(b==g)
    {
    memset(zarr,'B',sizeof(zarr));
    for(int i=1; i<z; i+=2)
    {
        if(count==g) break;
        else
        {
            zarr[i] = 'G';
            count++;
        }
    }
    for(int i=0; i<z; i++)
    {
        cout<<zarr[i];
    }
    }
    else
    {
        int mini = min(b,g);
        if(mini==g)
        {
          memset(zarr,'B',sizeof(zarr));

            for(int i=1; i<g*2; i+=2)
            {
                zarr[i]='G';
            }
        }
        else
        {
        memset(zarr,'G',sizeof(zarr));
        for(int i=1; i<b*2; i+=2)
        {
            zarr[i]='B';
        }
        }
    for(int i=0; i<z; i++)
    {
        cout<<zarr[i];
    }

    }

   return 0;
}
