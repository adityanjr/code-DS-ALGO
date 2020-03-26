#include <iostream>
using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, temp = 1;
	    cin >> n;
	    
	    string ans = "YES";
	    
	    if(n == 0){
	        ans = "NO";
	    }
	    
	    while(temp <= n){
	        if(!(temp & n)){
	            ans = "NO";
	            break;
	        }
	        temp = temp << 1;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
