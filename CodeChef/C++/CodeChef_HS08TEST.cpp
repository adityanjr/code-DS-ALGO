#include <bits/stdc++.h>

int main() {
	int n;
	float x;

	scanf("%d %f",&n,&x);
	
	if(n % 5 == 0 && (float)n <= x - 0.5) 
		x = x - (float)n - 0.5; 

	printf("%.2f",x );
	return 0;
}