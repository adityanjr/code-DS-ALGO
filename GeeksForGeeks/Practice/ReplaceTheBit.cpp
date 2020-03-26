#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, k;
	    cin >> n >> k;
	    
	    int temp = 1, bits = 0;
	    
	    while(temp <= n){
	        bits++;
	        temp = temp*2;
	    }
	    
	    temp = pow(2, bits-k);
	    
	    if((temp & n) != 0){
	        n = n - temp;
	    }
	    
	    cout << n << endl;
	    
	    test--;
	}
	
	return 0;
}
