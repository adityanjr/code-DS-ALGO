#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	while(t --) {
		int arr[3];
		scanf("%d %d %d",&arr[0], &arr[1], &arr[2]);

		sort(arr, arr+3);

		printf("%d\n",arr[1]);
	}

	return 0;
}