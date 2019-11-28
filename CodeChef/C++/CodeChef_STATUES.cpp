#include <bits/stdc++.h>
using namespace std;
int main() {
	int t = 1;
	while(t <= 2) {
		int n, temp, avg = 0; 
		scanf("%d",&n);
		vector<int> v;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
			avg += temp;
		}

		avg /= n;

		sort(v.begin(), v.end());

		temp = 0;
		for(int i = 0; v[i] != avg; i ++) {
			temp += (avg - v[i]);
		}

		printf("Set #%d\n",t);
		printf("The minimum number of moves is %d.\n",temp);
		printf("\n");
		t++;
	}

	scanf("%d",&t);

	return 0;
}