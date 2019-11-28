#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, temp;
		scanf("%d",&n);
		vector<int> v;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp*3);
		}

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v[i] += temp;
		}

		sort(v.begin(), v.end());

		printf("%d\n",v[n-1]);

	}

	return 0;
}