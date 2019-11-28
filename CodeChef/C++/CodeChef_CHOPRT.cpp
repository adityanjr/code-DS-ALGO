#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t --) {
		int a, b;
		scanf("%d %d",&a, &b);

		if(a > b)
			printf(">\n");
		else if(a < b)
			printf("<\n");
		else
			printf("=\n");
	}
}