// http://www.geeksforgeeks.org/lucky-numbers

#include <iostream>
using namespace std;

bool isLucky(int x){
	int pos = x;
	for(int i=2; i<=pos; i++){
		if(pos%i == 0)
			return false;
		pos -= ((pos-1)/i);
	}
	return true;
}

int main(){
	int x = 19;
  	if( isLucky(x) )
    	printf("%d is a lucky no.", x);
 	else
    	printf("%d is not a lucky no.", x);
	return 0;
}

