#include<iostream>
using namespace std;

int main()
{
	int a, b, min, max, temp=0;

	cin>>a>>b;
	
	if (a<b)
	{
		min = a;
		max= b;
	}
	else
	{
		min = b;
		max = a;
	}
	
	for(int i = (min +1); i< max; ++i)
	{
		if ( i % 2 == 1 || i % 2 == -1)
		{
			temp += i;
		}
	}
	cout<< temp << endl;
	
	return 0;
}