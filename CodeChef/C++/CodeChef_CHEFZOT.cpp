#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, count = 0, temp = 0;
	scanf("%d",&n);
	vector<int> v;

	int input;
	for(int i = 0; i < n; i ++) {
		cin >> input;
		v.push_back(input);
	}	

	for(int i = 0; i < n; i ++) {
		if(v[i] == 0)
			temp = 0;
		else
			temp ++;
		count = max(count, temp);
	}

	printf("%d\n",count);

	return 0;
}