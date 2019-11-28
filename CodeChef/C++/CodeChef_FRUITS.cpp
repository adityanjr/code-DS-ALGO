#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	while(t--) {
		int n, m, k;
		scanf("%d %d %d",&n,&m,&k);

		int diff = abs(n-m);

		if(diff > k)
			diff = diff - k;
		else if(diff <= k)
			diff = 0;

		printf("%d\n",diff);
	}

	return 0;
}