#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, k, count = 0, ans = -1;
	    cin >> n >> k;
	    
	    vector<int> temp(n+1, 1);
	    
	    for(int i = 2; i <= sqrt(n); i++){
	        for(int j = 2; i*j <= n; j++){
	            temp[i*j] = -1;
	        }
	    }
	    
	    int i = 2;
	    
	    while(n > 1){
	        if(temp[i] == 1){
    	        while(n%i == 0 && (n > 1)){
    	            n = n/i;
    	            count++;
    	            if(count == k){
    	                ans = i;
    	                goto ANS;
    	            }
    	        }
	        }
	        i++;
	    }
	    
	    ANS:cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
