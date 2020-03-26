//Header file for Bit Manupulation

#include <bits/stdc++.h>
using namespace std;

void printBinary(int A){
	string res = "";
	for(int i=0; i<32; i++){
		if(A&1)
			res = '1' + res;
		else
			res = '0' + res;
		A >>= 1;
	}
	cout<<res<<'\n';
}

