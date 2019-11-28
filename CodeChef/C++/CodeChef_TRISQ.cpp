#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		float b;
		scanf("%f",&b);

		float x = (((sqrt(4+pow(b,2)))-2)/2) ;
		// x = x * x;

		printf("%f\n",x);
	}

	return 0;
}