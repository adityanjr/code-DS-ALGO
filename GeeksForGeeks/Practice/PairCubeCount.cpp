#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0, count = 0;
	    cin >> n;
	    
	    int lim = pow(n, (double)1/3);
	    if(pow(lim, 3) != n){
	        lim++;
	    }
	   // cout << n << " " << lim << endl;
	    
	    if(n != 0){
    	    for(int i = 0; i <= lim; i++){
    	        for(int j = 1; j <= lim; j++){
    	            if((pow(i, 3) + pow(j, 3)) == n){
                        ans ++;     	           
    	                if(i == j){
    	                    count++;
    	                }
    	               // cout << i << " " << j << endl;
    	            }
    	        }
    	    }
	    }
	    
	    cout << ans-count/2 << endl;
	}
	
	return 0;
}
