#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    int last = -1, i = 0, ans = -1;
	    
	    while(i < n){
	        if(temp[i] == 1){
	            if(last == -1){
	                ans = i;
	            }    
	            else{
	                ans = max(ans, (i-last)/2);
	            }
	            last = i;
	        }
	        
	        if(i == n-1 && temp[i] == 0){
	            ans = max(ans, i-last);
	        }
	        
	        i++;
	    }
	    
	    if(last == -1){
	        ans = -1;
	    }
	    
	    cout << ans << endl;
	    
	}
	
	return 0;
}
