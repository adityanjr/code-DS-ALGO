// http://www.geeksforgeeks.org/find-smallest-number-whose-digits-multiply-given-number-n/

#include <iostream>
#include <cstdio>
using namespace std;

int findSmallest(int n){
	if(n < 10)
		return n+10;
	int res = 0;
	int pos = 1;
	for(int i=9; i>1 && n > 1; i--){
		while(n%i == 0){
			res = res + i*pos;
			pos *= 10;
			n /= i;
		}
	}
	if(n > 1)
		return -1;
	return res;
}

int main(){
	cout<<findSmallest(7);
    printf("\n");

    cout<<findSmallest(36);
    printf("\n");

    cout<<findSmallest(13);
    printf("\n");

    cout<<findSmallest(100);
	return 0;
}

