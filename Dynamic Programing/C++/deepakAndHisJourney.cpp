#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int C[n];
		long long int L[n];

		for (long long int i = 0; i < n; i++)
		{	long long int cost;
			cin>>cost;
			C[i] = cost;
			
		}
		for (long long int i = 0; i < n; i++)
		{	long long int petrol;
			cin>>petrol;
			L[i] = petrol;
			
		}
		long long int minCost = C[0];
		long long int val =0;
		for (long long int i = 0; i < n; i++)
		{
			minCost = min(minCost, C[i]);
			val += minCost*L[i]; 
			//cout<<val<<endl;
		}

		cout<<val<<endl;

	}
	return 0;
}