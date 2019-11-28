#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string ing1[4], ing2[4];
		for(int i = 0; i < 4; i ++) {
			cin >> ing1[i];
		}
		for(int i = 0; i < 4; i ++) {
			cin >> ing2[i];
		}

		int count = 0;
		for(int i = 0; i < 4; i ++) {
			for(int j = 0; j < 4; j ++) {
				if(ing1[i].compare(ing2[j]) == 0) {
					// cout << ing1[i]
					count ++;
				}
			}
		}

		if(count >= 2)
			printf("similar\n");
		else
			printf("dissimilar\n");
	}

	return 0;
}