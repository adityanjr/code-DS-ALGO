#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, count = 0;
		int input;
		scanf("%d",&n);
		vector<int> pies, racks;

		for(int i = 0; i < n; i ++) {
			int temp;
			scanf("%d",&temp);
			pies.push_back(temp);
		}
		sort(pies.begin(), pies.end());

		for(int i = 0; i < n; i ++) {
			int temp;
			scanf("%d",&temp);
			racks.push_back(temp);
		}
		sort(racks.begin(), racks.end());

		// for(int i = 0; i < n; i ++){
		// 	if(pies[i] <= racks[i])
		// 		count ++;
		// }

		// printf("%d\n",count);

		for (int i = 0; i < n; ++i) {
			printf("%d ", pies[i]);
		}
		printf("\n");

		for (int i = 0; i < n; ++i) {
			printf("%d ", racks[i]);
		}
		printf("\n");
	}

	return 0;
}