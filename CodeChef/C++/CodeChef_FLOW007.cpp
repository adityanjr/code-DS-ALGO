#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int arr[10];

		int count = 0;
		for(int i = 0; n != 0; i++) {
			arr[i] = n % 10;
			n /= 10;
			count++;
		}

		for(int i = 0; i<= count-1; i++) {
			printf("%d",arr[i]);
		}
		printf("\n");

	}

	return 0;
}