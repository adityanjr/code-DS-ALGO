#include <iostream>
#include <string>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    string s;
	    cin >> s;
	    
	    int ans = 0;
	    
	    for(int i = 0; i < n; i++){
	        int j = i-1, k = i;
	        
	        while(j >= 0 && k < n){
	            if(s[j] == s[k]){
	                ans++;
	            }
	            else{
	                break;
	            }
	            j--;
	            k++;
	        }
	        
	        j = i-1, k = i+1;
	        
	        while(j >= 0 && k < n){
	            if(s[j] == s[k]){
	                ans++;
	            }
	            else{
	                break;
	            }
	            j--;
	            k++;
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
