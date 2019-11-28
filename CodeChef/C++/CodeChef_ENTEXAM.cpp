#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		long long int n, k, e;
		long long int m;
		scanf("%lld %lld %lld %lld",&n,&k,&e,&m);

		long long int arr[n][e];
		long long int total[n-1]={0};

		for(long long int i = 0; i < n-1; i ++) {
			for(long long int j = 0; j < e; j ++) {
				scanf("%lld",&arr[i][j]);
				total[i] += arr[i][j];
			}
		}

		long long int sergey=0;
		for(long long int i = 0; i < e-1; i ++) {	
			long long int temp;
			scanf("%lld",&temp);
			sergey += temp;
		}

		sort(total, total+n-1);

		if(sergey > total[n-k-1])
			printf("1\n");
		else if(sergey <= total[n-k-1] && (total[n-k-1]-sergey+1 <= m))
			printf("%lld\n",(total[n-k-1]-sergey+1));
		else
			printf("Impossible\n");

	}	

	return 0;
}