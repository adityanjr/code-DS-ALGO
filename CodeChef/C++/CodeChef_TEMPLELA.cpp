#include <bits/stdc++.h>
using namespace std;

int main() {
	int s;
	scanf("%d",&s);

	while(s--) {
		int n, temp, flag = 1;
		scanf("%d",&n);
		std::vector<int> v;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}

		if(n % 2 == 0) {
			flag = 0;
		}
		else {
			for(int i = 1; i < ((n/2)+1); i ++) {
				if(v[i-1] != i || v[v.size()-i] != i) {
					flag = 0;
					// printf("%d here",i );
				}
			}
		}

		if(flag) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;
}