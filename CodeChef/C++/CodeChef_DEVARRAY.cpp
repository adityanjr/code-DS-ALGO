#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q, x;
	scanf("%d %d",&n,&q);

	vector<int> v;
	for(int i = 0; i < n; i ++) {
		scanf("%d",&x);
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int max = v[0];
	int min = v[n-1];

	while(q--) {
		int temp;
		scanf("%d",&temp);

		if(temp >= max && temp <= min) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}