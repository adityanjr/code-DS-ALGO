#include <iostream>
using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n, ans = 1;
	    
	    cin >> n;
	    
	    while(n != 1){
	        ans = ans*2;
	        n = n/2;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	
	return 0;
}
