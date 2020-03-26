// http://www.geeksforgeeks.org/fast-multiplication-method-without-using-multiplication-operator-russian-peasants-algorithm

#include <iostream>
#include <cstdio>
using namespace std;

int russianPeasant(int a, int b){
	if(b > a)
		return (b, a);
	int res = 0;
	while(b != 1){
		if(b%2 == 0){
			a *= 2;
			b /= 2;
		}
		else {
			b--;
			res += a;
		}
		
	}
	res += a;
	return res;
}

int main(){
	cout << russianPeasant(18, 1) << endl;
    cout << russianPeasant(20, 12) << endl;
	return 0;
}

