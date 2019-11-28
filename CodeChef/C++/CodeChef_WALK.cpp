#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		vector<int> v;

		int temp;
		int max = INT_MIN;
		for(int i = 0; i < n; i ++){
			cin >> temp;
			v.push_back(temp+i);
			if(temp+i > max)
				max = temp + i;
		}
	printf("%d\n",max);
	}

	return 0;
}