#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		int arr[10], count = 0;
		for (int i = 0; n != 0; i ++) {
			arr[i] = n % 10;
			n = n / 10; 
			count ++;
		}
		printf("%d\n",arr[0] + arr[count-1]);
	}

	return 0;
}