// http://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators

#include <bits/stdc++.h>
using namespace std;

int Add(int x, int y){
	int carry;
	while(y){
		carry = x&y;
		x = x^y;
		y = (carry<<1);
	}
	return x;
}

int main(){
	printf("%d", Add(15, 32));
	return 0;
}

