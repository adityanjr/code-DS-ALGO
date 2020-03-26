// http://geeksquiz.com/replace-0-5-input-integer/

#include <iostream>
#include <cstdio>
using namespace std;

int convert0To5(int n){
	int tmp = n;
	int t = 5;
	while(tmp){
		if(tmp%10 == 0){
			n = n+t;
		}
		tmp /= 10;
		t *= 10;
	}
	return n;
}

int main(){
	int num = 10120;
    printf("%d", convert0To5(num));
	return 0;
}

