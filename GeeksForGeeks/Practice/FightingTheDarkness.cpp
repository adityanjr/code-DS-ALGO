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
	    
	    int ans = temp[0];
	    
	    for(int i = 1; i < n; i++){
	        ans = max(ans, temp[i]);
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
