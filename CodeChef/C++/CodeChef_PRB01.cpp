#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
	for(int i = 2; i <= sqrt(n); i ++)
		if(n % i == 0)
			return false;

	return true;
}

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		
		int n;
		scanf("%d",&n);
		bool val = prime(n);
		
		if(val)
			printf("yes\n");
		else if(!val)
			printf("no\n");
	}

	return 0;
}