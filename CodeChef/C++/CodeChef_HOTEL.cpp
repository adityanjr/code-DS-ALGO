#include <bits/stdc++.h>
using namespace std;

struct Guest {
	int arrival;
	int departure;
};

bool comp(Guest b, Guest a) {
	return (a.arrival < b.arrival);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		vector<Guest> v;
		int temp;

		for(int i = 0; i < n; i ++) {
			v.push_back(Guest());
			scanf("%d",&temp);
			v[i].arrival = temp;
		}

		for(int i = 0; i < n; i ++) {
			v.push_back(Guest());
			scanf("%d",&temp);
			v[i].departure= temp;
		}

		sort(v.begin(), v.end(), comp);

		for(int i = n-1; i >= 0; i --) {
			printf("%d %d\n",v[i].arrival, v[i].departure);
		}
		printf("\n");

	}
}