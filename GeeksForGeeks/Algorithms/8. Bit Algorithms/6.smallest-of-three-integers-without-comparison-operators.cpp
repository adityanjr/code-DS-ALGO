// http://www.geeksforgeeks.org/smallest-of-three-integers-without-comparison-operators

#include <bits/stdc++.h>
#include "bit.h"
using namespace std;

int min(int x, int y){
	int shift = sizeof(int)*CHAR_BIT - 1;   //32-1
	return y + ((x-y)&((x-y)>>shift));  //(x-y) either represent -1 or 0;
}

int main(){
	int x = 15, y = 12, z = 5;
	cout<<min(min(x, z), y)<<'\n';
	return 0;
}

