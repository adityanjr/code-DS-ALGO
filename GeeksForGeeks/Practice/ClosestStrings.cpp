#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<string> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    string a, b;
	    cin >> a >> b;
	    
	    int i = 0, j = 0, ans = n, lasti = -1, lastj = -1;
	    
	   // for(int i = 0; i < n; i++){
	   //     cout << temp[i] << " ";
	   // }
	    
	   // cout << endl;
	    
	   // cout << a << " " << b;
	    
	   // cout << endl;
	    
	   // break;
	    
	    while(i < n && j < n){
	        if(i < j){
    	        while(i < n){
    	            if(temp[i] == a){
    	                lasti = i;
    	                i++;
    	                break;
    	            }
    	            i++;
    	        }
	        }
	        else{
    	        while(j < n){
    	            if(temp[j] == b){
    	                lastj = j;
    	                j++;
    	                break;
    	            }   
    	            j++;
    	        }
	        }
	        if(lastj != -1 && lasti != -1){
	            ans = min(ans, abs(lasti-lastj));
	        }
	    }
	    
	    while(i < n){
	        if(temp[i] == a){
                ans = min(ans, abs(lastj-i));
            }
            i++;    
	    }
	    
	    while(j < n){
	        if(temp[j] == b){
                ans = min(ans, abs(lasti-j));
            }
            j++;    
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
