#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		if(360 % n == 0)
			printf("y ");
		else 
			printf("n ");
		if(n <= 360)
			printf("y ");
		else
			printf("n ");

		int sum = ((n*(n+1))/2);
		
		if(sum <= 360)
			printf("y\n");
		else
			printf("n\n");
	} 

	return 0;
}