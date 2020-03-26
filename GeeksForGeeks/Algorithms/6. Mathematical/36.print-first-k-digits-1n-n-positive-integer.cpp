// http://geeksquiz.com/print-first-k-digits-1n-n-positive-integer/

#include <iostream>
#include <cstdio>
using namespace std;

void print(int n, int k){
	int tmp = 1;
	while(k){
		tmp *= 10;
		cout<<int(tmp/n);
		k--;
		tmp = tmp%n;
	}
}

int main(){
	int n = 7, k = 3;
    print(n, k);
    cout << endl;

    n = 21, k = 4;
    print(n, k);
	return 0;
}

