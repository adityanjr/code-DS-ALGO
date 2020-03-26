// http://www.geeksforgeeks.org/square-root-of-a-perfect-square

#include <iostream>
using namespace std;

float squareRoot(int n){
	float x = n;
	float y = 1;
	float e = 0.000001;
	while(x-y > e){
		x = (x+y)/2;
		y = n/x;
	}
	return x;
}

int main(){
	int n = 50;
  	printf ("Square root of %d is %f", n, squareRoot(n));
	return 0;
}

