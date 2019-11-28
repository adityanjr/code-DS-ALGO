#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int n;
		scanf("%lld",&n);

		long long int input;
		vector<long long int> v;
		for(int i = 0; i < n; i ++) {
			cin >> input;
			v.push_back(input);
		}

		sort(v.begin(), v.end());

		input = 0;
		for(int i = n - 1; i >= 0; i -= 2)
			input += v[i];

		printf("%lld\n",input);
	}

	return 0;
}