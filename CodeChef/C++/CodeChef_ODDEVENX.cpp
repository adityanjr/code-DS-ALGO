#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n, count_odd = 0, count_even = 0;
	scanf("%d",&n);
		
	vector<int> v;
	int temp;
	
	for(int i = 0; i < n; i ++) {
		cin >> temp;
		v.push_back(temp);
	}

	for(int i = 0; i < n; i ++) {
		if(v[i] % 2 == 0)
			count_even++;
		else
			count_odd++;
	}

	printf("%d\n",abs(count_odd - count_even));


	return 0;
}