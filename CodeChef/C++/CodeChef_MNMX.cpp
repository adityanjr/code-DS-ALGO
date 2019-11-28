#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		int arr[n], min = INT_MAX;
		for(int i = 0; i < n; i ++) {
			scanf("%d",&arr[i]);
			if(min > arr[i])
				min = arr[i];
		}

		printf("%d\n", min*(n-1));

	}

	return 0;
}