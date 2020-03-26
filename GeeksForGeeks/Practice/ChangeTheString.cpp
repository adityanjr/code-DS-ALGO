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
	    
	    int n = s.size(), i = 1;
	    bool small = true;
	    
	    if(s[0] >= 97 && s[0] <= 122){
	        small = false;
	    }
	    
	    // if statements to make the code fast
	    if(small){
	        while(i < n){
	            if(s[i] >= 97 && s[i] <= 122){
	                s[i] -= 32;
	            }
	            i++;
	        }
	    }
	    else{
	        while(i < n){
	            if(s[i] >= 65 && s[i] <= 90){
	                s[i] += 32;
	            }
	            i++;
	        }
	    }
	    
	    cout << s << endl;
	}
	
	return 0;
}
