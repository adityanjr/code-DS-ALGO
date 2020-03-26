#include <iostream>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0;
	    cin >> n;
	    
	    while(n != 1){
	        if(n%3 == 0){
	            n = n/3;
	            ans++;
	        }
	        else{
	            n--;
	            ans++;
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
