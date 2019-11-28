#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		int n;
		scanf("%d",&n);

		if((n-1)%8 == 0) {
			printf("%dLB\n",n+3);
		}
		else if(((n-4)%8 == 0)) {
			printf("%dLB\n",n-3);
		}
		else if((n-2)%8 == 0) {
			printf("%dMB\n",n+3);
		}
		else if((n-5)%8 == 0) {
			printf("%dMB\n",n-3);
		}
		else if((n-3)%8 == 0) {
			printf("%dUB\n",n +3);
		}
		else if((n-6)%8 == 0) {
			printf("%dUB\n",n -3);
		}
		else if((n-7) % 8 == 0){
			printf("%dSU\n",n+1 );
		}
		else 
			printf("%dSL\n",n-1);
	}


	return 0;
}