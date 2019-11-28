#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, temp;
		vector<int> v;
		scanf("%d",&n);

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}
		int val = v[0];
		for(int i = 1; i < v.size(); i ++) {
			val = __gcd(val, v[i]);
		}

		printf("%d\n",val);
	}

	return 0;
}