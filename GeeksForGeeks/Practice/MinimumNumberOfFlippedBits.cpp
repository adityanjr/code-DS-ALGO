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
	    
	    int i = 0, n = s.size(), odd1 = 0, odd0 = 0;
	    
	    while(i < n){
	        if(s[i] == '1'){
	            if(i%2 == 0){
	                odd1++;
	            }
	            else{
	                odd0++;
	            }
	        }
	        else{
	            if(i%2 == 0){
	                odd0++;
	            }
	            else{
	                odd1++;
	            }
	        }
	        i++;
	    }
	    
	    cout << min(odd1, odd0) << endl;
	}
	
	
	return 0;
}
