#include<bits/stdc++.h>
using namespace std;
int main()
{
    int j=0,count=0;
    string s;
    string arr[200];
    cin>>s;
    int si = s.size();
    for(int i=0; i<si; i++)
    {
        if(s[i]=='.')
        {
            arr[j]='0';
            j++;
            count++;
        }
        else if(s[i]=='-' && s[i+1]=='.')
        {
            arr[j]='1';
            i++;
            j++;
            count++;
        }
        else if(s[i]=='-' && s[i+1]=='-')
        {
           arr[j]='2';
           i++;
           j++;
           count++;
        }
    }
    for(int j=0; j<count; j++)
    {
        cout<<arr[j];
    }
   return 0;
}
