#include <iostream>
#include <cmath>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0, power = 0; 
	    cin >> n;
	    
	    while(n){
	        if(n & 1){
	            ans += pow(2, power+1);
	        }
	        if(n & 2){
	            ans += pow(2, power);
	        }
	        
	        power += 2;
	        n /= 4;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
