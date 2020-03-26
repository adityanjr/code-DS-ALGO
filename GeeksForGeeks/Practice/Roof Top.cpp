#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0, tempAns = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    for(int i = 1; i < n; i++){
	        if(temp[i] > temp[i-1]){
	            tempAns++;
	        }
	        else{
	            tempAns = 0;
	        }
	        
	        ans = max(ans, tempAns);
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
