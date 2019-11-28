// https://codeforces.com/contest/275/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4]={0,1,1,1}, brr[4]={0,1,1,1}, crr[4]={0,1,1,1};
    int marr[10];
    memset(marr,0,sizeof(marr));
    for(int i=1; i<10; i++) cin>>marr[i];

    if(marr[1]%2==1)
    {
        if(arr[1]==1) arr[1]=0; else arr[1]=1;
        if(arr[2]==1) arr[2]=0; else arr[2]=1;
        if(brr[1]==1) brr[1]=0; else brr[1]=1;
    }
    if(marr[2]%2==1)
    {
        if(arr[2]==1) arr[2]=0; else arr[2]=1;
        if(arr[1]==1) arr[1]=0; else arr[1]=1;
        if(arr[3]==1) arr[3]=0; else arr[3]=1;
        if(brr[2]==1) brr[2]=0; else brr[2]=1;
    }
    if(marr[3]%2==1)
    {
        if(arr[3]==1) arr[3]=0; else arr[3]=1;
        if(arr[2]==1) arr[2]=0; else arr[2]=1;
        if(brr[3]==1) brr[3]=0; else brr[3]=1;
    }
    if(marr[4]%2==1)
    {
        if(brr[1]==1) brr[1]=0; else brr[1]=1;
        if(brr[2]==1) brr[2]=0; else brr[2]=1;
        if(arr[1]==1) arr[1]=0; else arr[1]=1;
        if(crr[1]==1) crr[1]=0; else crr[1]=1;
    }
    if(marr[5]%2==1)
    {
        if(brr[2]==1) brr[2]=0; else brr[2]=1;
        if(brr[1]==1) brr[1]=0; else brr[1]=1;
        if(brr[3]==1) brr[3]=0; else brr[3]=1;
        if(arr[2]==1) arr[2]=0; else arr[2]=1;
        if(crr[2]==1) crr[2]=0; else crr[2]=1;
    }
    if(marr[6]%2==1)
    {
        if(brr[3]==1) brr[3]=0; else brr[3]=1;
        if(brr[2]==1) brr[2]=0; else brr[2]=1;
        if(arr[3]==1) arr[3]=0; else arr[3]=1;
        if(crr[3]==1) crr[3]=0; else crr[3]=1;
    }
    if(marr[7]%2==1)
    {
        if(crr[1]==1) crr[1]=0; else crr[1]=1;
        if(crr[2]==1) crr[2]=0; else crr[2]=1;
        if(brr[1]==1) brr[1]=0; else brr[1]=1;
    }
    if(marr[8]%2==1)
    {
        if(crr[2]==1) crr[2]=0; else crr[2]=1;
        if(crr[1]==1) crr[1]=0; else crr[1]=1;
        if(crr[3]==1) crr[3]=0; else crr[3]=1;
        if(brr[2]==1) brr[2]=0; else brr[2]=1;
    }
    if(marr[9]%2==1)
    {
        if(crr[3]==1) crr[3]=0; else crr[3]=1;
        if(crr[2]==1) crr[2]=0; else crr[2]=1;
        if(brr[3]==1) brr[3]=0; else brr[3]=1;
    }
    for(int i=1; i<=3; i++) cout<<arr[i];
    cout<<endl;
    for(int i=1; i<=3; i++) cout<<brr[i];
    cout<<endl;
    for(int i=1; i<=3; i++) cout<<crr[i];
    return 0;
}
