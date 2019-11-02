#include <iostream>

using namespace std;

int main()
{
	int n;
	cout<<"Enter the value of (n) : ";	
	cin>>n;

	for (int i = 1; i <= n; i++)
	{
		int k = 1;
		while(k != i)
		{
			cout<<" ";
			k++;
		}
		for(int j = i; j <= n; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}

	return 0;
}