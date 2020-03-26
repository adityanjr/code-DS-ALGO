#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int num = pow(10, 9) + 7, test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    if(n == 1 || n == 2){
	        cout << "1" << endl;
	    }
	    else{
	        long int n1 = 1, n2 = 1;
	        
	        while(n > 2){
	            long int n3 = (n1 + n2)%num;
	            n1 = n2%num;
	            n2 = n3;
	            n--;
	        }
	        
	        cout << n2 << endl;
	    }
	    
	    test--;
	}
	
	return 0;
}
