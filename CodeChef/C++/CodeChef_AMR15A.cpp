#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);

	int count_odd = 0, count_even = 0;

	int arr[n];
	for(int i = 0; i < n; i ++) {
		scanf("%d",&arr[i]);
		if(arr[i] % 2 == 1)
			count_odd++;
		else if(arr[i] % 2 == 0)
			count_even++;
	}

	if(count_even > count_odd)
		printf("READY FOR BATTLE\n");
	else
		printf("NOT READY\n");

	return 0;
}