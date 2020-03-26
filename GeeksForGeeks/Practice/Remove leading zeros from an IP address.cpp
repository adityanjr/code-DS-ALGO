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
	    
	    int n = s.size(), include0 = 0, i = 0;
	    string ans = "";
	    
	    while(i < n){
	        if(s[i] == '.'){
	            if(ans.size() == 0 || ans[ans.size()-1] == '.'){
	                ans += '0';
	            }
	            ans += s[i];
	            include0 = 0;
	        }
	        else{
	            if(include0){
	                ans += s[i];
	            }
	            else{
    	            if(s[i] != '0'){
    	                ans += s[i];
    	                include0 = 1;
    	            }
	            }
	        }
	        
	        i++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
