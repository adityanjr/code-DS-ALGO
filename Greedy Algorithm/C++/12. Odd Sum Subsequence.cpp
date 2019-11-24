// # Odd Sum Subsequence

// You are given sequence *a<sub>1</sub>*, *a<sub>2</sub>*, ..., *a<sub>n</sub>* of integer numbers of length *n*. 
// Your task is to find such subsequence that its sum is odd and maximum among all such subsequences. 
// It's guaranteed that given sequence contains subsequence with odd sum.

// Subsequence is a sequence that can be derived from another sequence by deleting some elements 
// without changing the order of the remaining elements.

// You should write a program which finds sum of the best subsequence.


#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b)
{
	return a>b ? a:b;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	int min = 1000000,max = -1000000,sum = 0;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
		if(arr[i] > 0)
		{
			sum += arr[i];
			if(arr[i]%2 == 1 && arr[i] < min)
			{
				min = arr[i];
			}
		}
		else if(arr[i] < 0)
		{
			if(abs(arr[i])%2 == 1 && arr[i] > max)
			{
				max = arr[i];
			}
		}
	}
	if(sum%2 == 0)
	{
		sum = maximum(sum-min,sum+max);
	}
	cout << sum << endl;
}
