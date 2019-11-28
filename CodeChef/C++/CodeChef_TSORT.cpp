#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	scanf("%d",&n);
	int arr[n];

	for(int i = 0; i < n; i ++) {
		scanf("%d",&arr[i]);
	}

	sort(arr, arr+n);

	for(int i = 0; i < n; i ++)
		printf("%d\n", arr[i]);

	return 0;
}