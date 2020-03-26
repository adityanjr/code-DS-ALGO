// http://www.geeksforgeeks.org/add-1-to-a-given-number

#include <bits/stdc++.h>
using namespace std;

int addOne(int x){
	int m = 1;
	while(x&m){
		x = x^m;
		m <<= 1;
	}
	x = x|(m);
	return x;
}

int main(){
	printf("%d", addOne(7));
	return 0;
}

