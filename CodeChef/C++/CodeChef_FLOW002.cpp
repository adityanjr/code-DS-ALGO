#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b;
		scanf("%d %d",&a,&b);
		a = a % b;
		printf("%d\n",a );
	}
	return 0;
}
