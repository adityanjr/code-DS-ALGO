#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	int a, n, k;
	scanf("%d %d %d",&a,&n,&k);

	for(int i = 0; i < k; i ++) { 
		v.push_back(a%(n+1));
		a /= (n+1);
		// printf("%d ",a);
	}
	// printf("\n");

	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	printf("\n");

	return 0;
}