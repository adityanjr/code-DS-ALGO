#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		int n, l, a, b;
		scanf("%d %d %d %d",&n,&l,&a,&b);

		int s[n];
		for(int i = 0; i < n; i ++) {
			scanf("%d",&s[i]);
		}

		sort(s, s+n);

		int min = a;
		int ans = 0;
		for(int i = 0; i < n; i ++) {
			ans += abs(min - s[i]);
			min += l;
		}

		printf("%d\n",ans);
	}

	return 0;
}