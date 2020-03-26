#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int n = s.size(), i = 1, ans = s[0] - '0';
	    
	    while(i < n){
	        int next = s[i+1]-'0';
	        if(s[i] == 'A'){
	            ans = (ans & next);
	        }
	        else if(s[i] == 'B'){
	            ans = (ans || next);
	        }
	        else{
	            ans = (ans ^ next);
	        }
	        i += 2;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
