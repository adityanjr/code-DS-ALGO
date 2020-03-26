#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0, curr = 1;
	    cin >> n;
	    
	    while(curr <= n){
	        n -= curr;
	        curr++;
	        ans++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
