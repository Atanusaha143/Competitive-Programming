#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q,rs,count,mount;
    cin>>q;

    while(q--)
    {

        count=0;
        mount=0;
        int n;
        cin>>n;

        int a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        if(n==1)
            {
                cout<<"1"<<endl;

            }

        else if(n==2)
            {
                int c;
                c=abs(a[0]-a[1]);
                if(c>1)
                    cout<<"1"<<endl;
                else
                    cout<<"2"<<endl;
            }

        else
        {
            sort(a,a+n);

            for(int i=0;i<n-1;i++)
            {
                rs=abs(a[i+1]-a[i]);
                if(rs>1)
                    count++;

            }

            if(count==(n-1))
            {
                cout<<"1"<<endl;
            }
            else
            {
                cout<<"2"<<endl;
            }

        }



    }


    return 0;
}
