#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a + b + c == 180 & a != 0 & b != 0 & c != 0)
			printf("YES\n");
		else 
			printf("NO\n");

	}
}