#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	while(t--) {
		float a,b,c;
		scanf("%f %f %f",&a,&b,&c);

		bool a1, b1, c1;
		a1 = a > 50;
		b1 = b < 0.7;
		c1 = c > 5600;

		if(a1 && b1 && c1)
			printf("10\n");
		else if(a1 && b1)
			printf("9\n");
		else if(b1 && c1)
			printf("8\n");
		else if(a1 && c1)
			printf("7\n");
		else if(a1 || b1 || c1)
			printf("6\n");
		else
			printf("5\n");

	}

	return 0;
}