#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 3;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    if(n <= 2){
	        ans = 0;
	    }
	    else{
	        bool inc = true, dec = true;
	        
	        for(int i = 1; i < n; i++){
	            if(temp[i] > temp[i-1]){
	                dec = false;
	            }
	            else if(temp[i] < temp[i-1]){
                    inc = false;    
	            }
	            else{
	                inc = false;
	                dec = false;
	                break;
	            }
	        }
	        
	        if(inc || dec){
	            ans = 0;
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
