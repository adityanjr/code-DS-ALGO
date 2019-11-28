#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	
	while(t--) {
		int n, k;
		scanf("%d %d",&n,&k);

		int votes[n]={0};
		for(int i = 0; i < n; i ++) {
			int temp;
			scanf("%d",&temp);
			if(temp == i+1)
				votes[i] = INT_MIN;
			else if(temp <= n)
				votes[temp-1]++;
		}

		int count = 0;
		for(int i = 0 ; i < n; i ++)
			if(votes[i] >= k)
				count++;

		printf("%d\n",count);

	}

	return 0;
}