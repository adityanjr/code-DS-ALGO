#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int n;
		scanf("%lld",&n);

		long long int count = 0, i = 1;
		while(n > 0){
			n -= i;
			i++;
			if(n >= 0)
				count ++;
		}

		printf("%lld\n",count);
	}	

	return 0;
}