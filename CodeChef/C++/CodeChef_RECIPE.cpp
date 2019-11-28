#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
    int temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		int arr[n];
		for(int i = 0; i < n; i ++)
			scanf("%d",&arr[i]);

		int result = arr[0];
	    for(int i=1; i<n; i++) {
	        result = gcd(result, arr[i]);
	    }

		for(int i = 0; i < n; i ++)
			printf("%d ",arr[i]/result);
		printf("\n");
	}

	return 0;
}