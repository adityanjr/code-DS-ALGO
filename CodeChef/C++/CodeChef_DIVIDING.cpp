#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);

	int temp, val = 0;

	for(int i = 0; i < n; i ++) {
		scanf("%d",&temp);
		val += temp;
	}

	temp = (n*(n+1))/2;

	if(temp != val) {
		printf("NO\n");
	}
	else
		printf("YES\n");
}