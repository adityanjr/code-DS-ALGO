#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, k;
	    cin >> n >> k;
	    
	    int m = 0, tempK = k, kNum = 1;
	    
	    while(tempK){
	        if((n & kNum) != 0){
	            m += kNum;
	        }
	        tempK--;
	        kNum = kNum*2;
	    }
	    
	    if(n & kNum){
	        m += kNum;
	    }
	    
	    if(m < kNum){
	        n += kNum;
	    }
	    
	    cout << n << endl;
	}
	
	return 0;
}
