#include <iostream>
using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    int ans = -1, temp = 0, count = 0;
	    
	    while(n){
	        if(count >= 1 && n%2 == 0){
	            temp++;
	        }
	        else if(n%2 == 1){
	            temp = 0;
	            count++;
	        }
	        n = n/2;
	        
	        ans = max(ans, temp);
	    }
	    
	    if(count == 1){
	        ans = -1;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	return 0;
}
