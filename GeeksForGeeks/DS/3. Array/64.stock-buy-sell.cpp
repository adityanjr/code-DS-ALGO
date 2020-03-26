// http://www.geeksforgeeks.org/stock-buy-sell

#include <iostream>
#include "array.h"

void stockBuySell(int *a, int n){
	int min=0, max=0;
	for(int i=1; i<n; i++){
		if(a[i] >= a[max])
			max = i;
		else {
			if(min < max)
				cout<<"by in day: "<<min<<" sell in day: "<<max<<'\n';
			min = i;
			max = i;
		}
	}
	if(min<max)
		cout<<"by in day: "<<min<<" sell in day: "<<max;
}

int main(){
	int price[] = {100, 80, 60, 10, 4, 3, 2};
    int n = sizeof(price)/sizeof(price[0]);
    // fucntion call
    stockBuySell(price, n);
	return 0;
}

