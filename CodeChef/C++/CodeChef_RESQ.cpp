#include <bits/stdc++.h>
using namespace std;

int div(int a) {
	
	int min = INT_MAX;
	for(int i = 1; i <= a; i ++) {
		if(a%i == 0) {
			int x = a / i;
			if(abs(x-i) < min)
				min = abs(x-i);
		}
	}

	return min;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		int x = div(n);

		printf("%d\n",x);
	}

	return 0;
}