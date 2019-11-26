// ## Problem Description

// Given a non-negative number up to 10 digits long, find the largest number that can be 
// formed with the digits and is divisible by 3. If no number can be formed that is divisible by 3, return 0.

// Input: int
// Output int

// Examples:
// - largest_div_by_three(0) -> 0
// - largest_div_by_three(24) -> 42
// - largest_div_by_three(319) -> 93
// - largest_div_by_three(113) -> 3
// - largest_div_by_three(111) -> 111

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string input;
	cin >> input;
	vector<int> digits;
	for (size_t i = 0; i < input.length(); i++)
	{
		int d = input[i] - '0';
		digits.push_back(d);
	}
	
	unsigned long long max = 0;
	for (size_t i = 0; i < digits.size(); i++)
	{
		sort(digits.begin(), digits.end(), [](int a, int b) { return a < b; });
		while (next_permutation(digits.begin(), digits.end()))
		{			
			int sum = 0;
			string str = "";
			for (size_t j = 0; j < digits.size() - i; j++)
			{
				sum += digits[j];
				str += to_string(digits[j]);
			}
			if (sum % 3 == 0)
			{
				sort(str.begin(), str.end(), [](char a, char b) { return a > b; });
				int n = stoi(str);
				if (n > max) max = n;
			}
		}
	}	
	
	cout << max << endl;

	return 0;
}
