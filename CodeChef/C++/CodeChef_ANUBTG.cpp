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
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		int total = 0;
		for(int i = v.size()-1; i >= 0; i -= 4) {
			total += v[i] + v[i-1];
		}

		printf("%d\n",total);
	}
	return 0;
}