#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
	if(n <= 1)
		return 1;

	int temp = 1;
	for(int i = 1; i <= n; i ++)
		temp = temp * i;

	return temp;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n = 11, temp;
		vector<int> v;
		
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		scanf("%d",&temp);
		int j = v[n - temp + 1];

		int count = 0;
		for(int i = 0; i < n; i ++)
			if(v[i] == j)
				count ++;

		if(count == 1)
			printf("%d\n",count);
		else
			printf("%d\n",( factorial(count) / (factorial(count-2) * (factorial(2) )) ) );
	}
}