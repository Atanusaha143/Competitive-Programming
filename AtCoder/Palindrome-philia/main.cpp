#include<bits/stdc++.h>
using namespace std;

void change(string s)
{
	int n = s.length();
	int cc = 0;
	for(int i=0;i<n/2;i++)
	{
		if(s[i]== s[n-i-1])
			continue;
		cc+= 1;
	}
	cout<<cc<<endl;
}

int main()
{
string s;
cin>>s;
change((s));
return 0;
}
