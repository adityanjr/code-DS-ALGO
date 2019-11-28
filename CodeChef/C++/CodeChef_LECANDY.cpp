#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, c, temp, count = 0;
		scanf("%d %d",&n,&c);

		vector<int> v;
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
			count += temp;
		}

		if(count > c)
			printf("No\n");
		else
			printf("Yes\n");
	}
}