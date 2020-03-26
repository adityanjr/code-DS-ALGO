#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 1;
	    cin >> n;
	    
	    vector<int> bit(n+1, 0);
	    
	    for(int i = 0; i <= n; i++){
	        if(i%2){
	            bit[i] = bit[i-1] + 1;
	        }
	        else{
	            bit[i] = bit[i/2];
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        if((i + bit[i]) == n){
	            ans = 0;
	            break;
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
