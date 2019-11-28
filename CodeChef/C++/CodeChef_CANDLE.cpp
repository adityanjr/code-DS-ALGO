#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		vector<int> v1;
		int temp;
		int n = 10;
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v1.push_back(temp);
		}
		

		int flag = 1;
		for (int i = 1; flag != 0; ++i) {
			vector<int> v2;
			for(int i = 0; i < n; i ++) {
				v2.push_back(0);
			}
			int temp_i = i;
			while(temp_i > 0) {
				temp = temp_i % 10;
				v2[temp]++;
				temp_i /= 10;
			}

			for(int j = 0; j < n; j ++) {
				if(v1[j] < v2[j]) {
					flag = 0;
					printf("%d\n",i);
					break;
				}
			}
		}

	}

	return 0;
}