#include<bits/stdc++.h>
using namespace std;


int main()
{
    char s[1000];
    gets(s);

    int count=0;

    if((s[0]>='A' && s[0]<='Z') || (s[0]>='a' && s[0]<='z'))
        {
            count=1;
        }


    for(int i=0;s[i];i++)

    {
        if(s[i]==' ' ||s[i]=='.' || s[i]==',' ||s[i]=='!' ||s[i]=='?' )
        {
            if(s[i+1]>='A' && s[i+1]<='Z' || s[i+1]>='a' && s[i+1]<='z')
                {
                    count++;
                }
        }
    }

    cout<<endl<<count;


    return 0;
}
