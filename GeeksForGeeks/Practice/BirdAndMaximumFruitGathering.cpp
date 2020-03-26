#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, k, total = 0;
	    cin >> n >> k;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        total += num;
	        temp[i] = total;
	    }
	    
	    int ans;
	    
	    if(k >= n){ 
	        ans = temp[n-1];
	    }
	    else{
    	    ans = temp[k-1];
    	    
    	    for(int i = 1; i < n; i++){
    	        if(i+k-1 < n){
    	            ans = max(ans, temp[i+k-1]-temp[i-1]);    
    	        }
    	        else{
    	            ans = max(ans, temp[(i+k-1)%n]+temp[n-1]-temp[i-1]);
    	        }
    	    }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
