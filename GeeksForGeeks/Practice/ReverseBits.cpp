#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    long int t = 1, ans = 0, p = 0;
	    
	    while(t <= n){
	        if(t & n){
	            ans += pow(2, 31-p);    
	        }
	        p++;
	        t = t << 1;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
