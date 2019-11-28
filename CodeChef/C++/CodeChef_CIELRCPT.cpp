#include <bits/stdc++.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t --) {
		int n;
		scanf("%d",&n);
		int count = 0;
		
		while(n > 0) {
			int count_cycle = 0;
			int arr[12]={0};
			for(int i = 0; i < 11; i ++) {
				arr[i] = n % 2;
				n = n / 2;
				if(arr[i] == 1)
					count_cycle ++;
			}
			if (count_cycle == 0)
				count_cycle ++;
			count += count_cycle;
		}
		printf("%d\n",count );
	}
	return 0;
}