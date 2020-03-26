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
	    
	    vector<int> pos(n, 0);
	    vector<int> neg(n, 0);
	    
	    if(temp[0] > 0){
	        pos[0] = temp[0];
	    }
	    else{
	        neg[0] = temp[0];
	    }
	    
	    int ans = temp[0];
	    
	    for(int i = 1; i < n; i++){
	        if(temp[i] > 0){
	            pos[i] = max(temp[i], pos[i-1]*temp[i]);
	            neg[i] = min(neg[i-1]*temp[i], temp[i]);
	        }
	        else{
	            pos[i] = max(temp[i]*neg[i-1], temp[i]);
	            neg[i] = min(pos[i-1]*temp[i], temp[i]);
	        }
	        ans = max(ans, pos[i]);
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
