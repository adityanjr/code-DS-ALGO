#include <bits/stdc++.h>
using namespace std;

int main() {

	int a,b;
	scanf("%d %d",&a,&b);
	int diff = abs(a-b);
	a = diff % 10;
	if(a == 9)
		diff --;
	else
		diff++;

	printf("%d\n",diff );

	return 0;
}