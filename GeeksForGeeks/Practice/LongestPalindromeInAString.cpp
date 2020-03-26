#include <iostream>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int n = s.size(), i = 0, start = -1, end = -1, len = 0;
	    
	    while(i < n){
	        // even check
	        int j = i-1, k = i, tstart = -1, tend = -1;
	        
	        while(j >= 0 && k < n){
	            if(s[j] != s[k]){
	                break;
	            }
	            tstart = j;
	            tend = k;
	            j--;
	            k++;
	        }
	        
	        if(len < tend-tstart+1 && tstart != -1 && tend != -1){
	            len = tend - tstart + 1;
	            start = tstart;
	            end = tend;
	        }
	        
	        // odd check
	        j = i-1, k = i+1, tstart = i, tend = i;
	        
	        while(j >= 0 && k < n){
	            if(s[j] != s[k]){
	                break;
	            }
	            tstart = j;
	            tend = k;
	            j--;
	            k++;
	        }
	        
	        if(len < tend-tstart+1 && tstart != -1 && tend != -1){
	            len = tend - tstart + 1;
	            start = tstart;
	            end = tend;
	        }
	        
	        i++;
	    }
	    
	    for(int i = start; i <= end; i++){
	        cout << s[i];
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
