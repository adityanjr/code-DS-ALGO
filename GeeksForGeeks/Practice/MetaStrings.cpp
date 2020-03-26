#include <iostream>
#include <string>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    int first = -1, second = -1, n = s1.size(), m = s2.size(), i = 0, count = 0, ans = 1;
	    
	    if(n != m){
	        ans = 0;
	        goto ANS;
	    }
	    
	    while(i < n){
	        if(s1[i] != s2[i]){
	            if(first == -1){
	                first = i;
	            }
	            else if(second == -1){
	                second = i;
	                if(s1[first] != s2[second]){
	                    ans = 0;
	                    goto ANS;
	                }
	                if(s2[first] != s1[second]){
	                    ans = 0;
	                    goto ANS;
	                }
	            }
	            
	            count++;
	            
	            if(count > 2){
    	            ans = 0;
    	            goto ANS;
    	        }    
	        }
	        
	        
	        i++;
	    }
	    
	    if(!count){
	        ans = 0;
	    }
	    
	    ANS:cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
