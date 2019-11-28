#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		int zeroes = 0, ones = 0;
		int arr[n];

		for(int i = 0; i < n; i ++) {
			scanf("%d",&arr[i]);
			if(arr[i] == 0)
				zeroes++;
			else if(arr[i] == 1)
				ones++;
		}

		if(zeroes%2 == 0 && ones%2 == 0)
			printf("0\n");
		else if(zeroes%2 == 1 && ones%2 == 0)
			printf("%d\n",zeroes);
		else if(zeroes%2 == 0 && ones%2 == 1)
			printf("%d\n",ones);
		else if(zeroes%2 == 1 && ones%2 == 1)
			printf("%d\n",ones);

	}

	return 0;
}