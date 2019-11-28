#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, temp,count = 0;
	scanf("%d",&n);
	set<int> s;
	for(int i = 0; i < n; i ++) {
		cin >> temp;
		s.insert(temp);
	}

	for(int i = 0; i <= n; i ++) {
		if(!s.count(i))
			printf("%d ",i);
	}
	printf("\n");

	return 0;
}