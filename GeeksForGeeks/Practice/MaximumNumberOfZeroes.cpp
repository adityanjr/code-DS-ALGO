#include <iostream>
#include <vector>

using namespace std;

int main()
 {
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
	    
	    int maxi = -1, ans = 0;
	    
	    for(int i = 0; i < n; i++){
	        int tmaxi = temp[i], tans = 0;
	        while(tmaxi){
	            if(tmaxi%10 == 0){
	                tans++;    
	            }
	            tmaxi = tmaxi/10;
	        }
	        
	        if(tans > ans){
	            ans = tans;
	            maxi = temp[i];
	        }
	        else if(tans == ans & ans != 0){
	            if(temp[i] > maxi){
	                maxi = temp[i];
	            }
	        }
	    }
	    
	    cout << maxi << endl;
	   // cout << ans << endl;
	}
	
	return 0;
}
