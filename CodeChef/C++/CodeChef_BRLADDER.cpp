#include <bits/stdc++.h>
using namespace std;

int main() {

	int q;
	scanf("%d",&q);
	while(q--) {
		long long int a, b;
		scanf("%lld %lld",&a,&b);
		
		if((a > 2) && a%2 == 0){
			if(b==a-2 || b==a-1 || b == a+2) {
				printf("YES\n");
			}
			else 
				printf("NO\n");
		}
		else if((a > 2) && a%2 != 0) {
			if(b==a-2 || b==a+1 || b == a+2) {
				printf("YES\n");
			}
			else 
				printf("NO\n");
		}
		else if(a==1) {
			if(b==2||b==3)
				printf("YES\n");
			else 
				printf("NO\n");
		}
		else if(a==2) {
			if(b==1 || b==4)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}
