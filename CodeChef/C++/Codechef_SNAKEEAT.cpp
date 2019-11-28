#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		long long int n, q, temp;
		scanf("%lld %lld",&n,&q);

		std::vector<long long int> v;

		for(int i = 0; i < n; i ++) {
			scanf("%lld",&temp);
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		long long int max;
		for(long long int i = 0; i < q; i ++) {
			long long int count = 0;
			long long int lim = 0;

			scanf("%lld",&max);
			
			for(int i = n-1; i >= lim; i --) {
				if(v[i] >= max) {
					count ++;
					// printf("->%d\t",i);
				}
				else if(v[i] < max) {
					if(max-v[i] <= i) {
						lim += abs(max-v[i]);
						count ++;
						// printf("->%d\t",i);
					}
				}
			}

			printf("%lld\n",count);

		}

	}

	return 0;
}