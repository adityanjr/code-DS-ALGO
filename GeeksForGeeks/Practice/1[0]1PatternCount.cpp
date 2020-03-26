#include <iostream>
#include <string>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int ans = 0;
	    bool one = false, other = false, zero = false;
	    
	    for(int i = 0; i < s.size(); i++){
	        if(s[i] == '1'){
	            if(one && !other && zero){
	                ans++;
	            }
	            one = true;
	            other = false;
	            zero = false;
	        }
	        else if(s[i] == '0'){
	            zero = true;
	        }
	        else{
	            other = true;
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
