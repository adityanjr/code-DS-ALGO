#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int k, val;
		scanf("%d",&k);
		
		int Div = 103993;
		int div = 33102;

		if(k > 0)
			printf("3.");
		else
			printf("3");

		Div = Div % div;
		
		for(int i = 0; i < k; i ++) {
			Div = Div * 10;
			val = (Div / div);
			printf("%d",val);
			Div = (Div % div);
		}
		printf("\n");
	}

	return 0;
}