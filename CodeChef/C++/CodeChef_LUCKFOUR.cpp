#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	
	while(t--) {
		long long int n;
		scanf("%lld",&n);

		int count = 0;
		while(n > 0) {
			int temp = n % 10;
			if(temp == 4)
				count ++;
			n /= 10;
		}

		printf("%d\n",count);
	}

	return 0;
}