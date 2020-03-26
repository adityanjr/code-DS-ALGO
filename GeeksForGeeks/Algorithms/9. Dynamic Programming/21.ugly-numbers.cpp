// http://www.geeksforgeeks.org/ugly-numbers/

#include <iostream>
#include <cstring>
using namespace std;

int getNthUglyNo(int n){
	int ugly[200];
	ugly[0] = 1;
	int k = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	int res;
	while(k<=n){
		int num2 = ugly[i2]*2;
		int num3 = ugly[i3]*3;
		int num5 = ugly[i5]*5;
		res = min(num2, min(num3, num5));
		ugly[k] = res;
		k++;
		if(res == num2){
			i2++;
		}
		if(res == num3){
			i3++;
		}
		if(res == num5){
			i5++;
		}
	}
	return ugly[n-1];
}

int main() {
	unsigned no = getNthUglyNo(150);
    printf("%dth ugly no. is %d ", 150, no);
	return 0;
}

