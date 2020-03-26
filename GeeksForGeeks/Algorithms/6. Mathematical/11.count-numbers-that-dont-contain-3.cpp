// http://www.geeksforgeeks.org/count-numbers-that-dont-contain-3

#include <iostream>
#include <cstdio>
using namespace std;

int count(int n){
	if(n<3)
		return n;
	if(n>=3 && n<10)
		return n-1;
	int pos=1;
	while(n/pos > 9){
		pos *=10;
	}
	int msd = n/pos;
	if(msd != 3){
		return count(msd)*count(pos-1) + count(msd) + count(n%pos);
	}
	return count(msd*pos - 1);
	
}

int main(){
	printf ("%d ", count(578));
	return 0;
}

