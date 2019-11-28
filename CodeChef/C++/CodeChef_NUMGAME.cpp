#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		//Alice -> True
		//Bob -> False
		bool flag = true;

		//Core logic
		for (int i = n/2; i > 0; i--) {
			if(n % i == 0) {
				n -= i;
				break;
			}
			else
				flag = !flag;
		}

		if(!flag)
			printf("ALICE\n");
		else
			printf("BOB\n");
	}

	return 0;
}