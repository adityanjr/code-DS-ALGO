#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);

	while(t--) {
		int n, temp, sum = 0, min = INT_MAX;
		scanf("%d",&n);
		vector<int> v;

		for (int i = 0; i < n; ++i) {
			scanf("%d",&temp);
			v.push_back(temp);

			sum += temp;

			if(temp < min)
				min = temp;
		}

		printf("%d\n",(sum-(min*n)));

	}

	return 0;
}