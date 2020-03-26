#include <iostream>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, i = 1, ans = 0;
	    cin >> n;
	    
	    while(i <= n){
	        if(i & n){
	            ans++;    
	            break;
	        }
	        ans++;
	        i = i << 1;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
