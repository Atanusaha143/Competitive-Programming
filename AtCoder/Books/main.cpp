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
#define Max 1000005
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define READ 		freopen("input.txt","r",stdin)
#define WRITE  		freopen("output.txt","w",stdout)
using namespace std;

int main()
{
    //IOS;

    LL books,total_time,sum_time=0,k=1,count=0;
    cin>>books>>total_time;
    LL arr[books+1];
    LL brr[books+1];
    memset(brr,0,sizeof(brr));
    for(int i=1; i<=books; i++) cin>>arr[i];
    for(int i=1; i<=books; i++)
    {
        sum_time+=arr[i];
        if(i==books && sum_time>total_time) break;
        else if(i==books && sum_time<=total_time)
        {
            count++;
            brr[k] = count;
            break;
        }
        else if(sum_time==total_time)
        {
            count++;
            brr[k] = count;
            k++;
            i = k;
            count = 0;
            sum_time = 0;
        }
        else if(sum_time>total_time)
        {
            brr[k] = count;
            k++;
            i = k;
            count = 0;
            sum_time = 0;
        }
        else count++;
    }
    LL maxi = brr[1];
    for(int i=2; i<=k; i++)
    {
        if(maxi<=brr[i])
        {
            maxi = brr[i];
        }
    }
    for(int i=1; i<=k; i++) cout<<brr[i]<<" ";
    cout<<endl;
    cout<<maxi<<endl;
}
