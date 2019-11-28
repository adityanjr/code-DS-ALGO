#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int temp = n;
		int arr[6], count = 0;
		while(temp > 0) {
			arr[count++] = temp % 10;
			temp /= 10;
		}

		temp = 0;
		for(int i = count; i > 0; i --) {
			temp += (arr[count-i]*pow(10, i));
		}
		temp /= 10;

		if(n == temp)
			printf("wins\n");
		else
			printf("losses\n");
	}

	return 0;
}