#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long a,i,sum=0;
	cin>>a;
	long long arr[a];
	for(i=0; i<a; i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<sum<<"\n";

	return 0;
}
