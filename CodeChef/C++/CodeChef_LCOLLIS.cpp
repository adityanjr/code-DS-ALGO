#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
	if(n <= 1)
		return 1;

	int temp = 1;
	for(int i = 1; i <= n; i ++) {
		temp *= i;
	}
	return temp;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int m,n;
		scanf("%d %d",&n,&m);

		string arr[n];

		for(int i = 0; i < n; i ++)
			cin >> arr[i];


		int count, total=0;
		
		for(int j = 0; j < m; j ++) {
			count = 0;
			for(int i = 0; i < n; i ++) {
				if(arr[i][j] == '1')
					count++;
			}
			
			if(count > 1)
				total += ((fact(count)/(fact(2)*fact(count-2))));
		}

		printf("%d\n",total);
	}

	return 0;
}