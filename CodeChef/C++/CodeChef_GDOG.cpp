#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	while(t--) {
		int n, k;
		scanf("%d %d",&n,&k);

		int val= INT_MIN;
		for(int i = 1; i <= k; i ++) {
			if(n % i > val)
				val = n % i;
		}

		printf("%d\n",val);
	}

	return 0;
}