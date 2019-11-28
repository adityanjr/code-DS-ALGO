#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
	return ((a > b) ? a : b);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d\n",max(a,b), a+b);
	}
	
	return 0;
}