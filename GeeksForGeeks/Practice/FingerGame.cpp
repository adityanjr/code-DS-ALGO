#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){ 
	    int n;
	    cin >> n;
	    
	    while(n > 8){
	        n -= 8;
	    }
	    
	    if(n <= 5){
	        cout << n;
	    }
	    else{
	        cout << 10-n;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
