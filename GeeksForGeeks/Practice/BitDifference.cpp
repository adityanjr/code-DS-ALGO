#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int a, b, ans = 0;
	    cin >> a >> b;
	    
	    int i = 1;
	    
	    while(i <= a || i <= b){
	        if((i & a) != (i & b)){
	            ans++;
	        }
	        i = i << 1;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
