#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    int ans = 1;
	    
	    for(int i = 1; i < n; i++){
	        if(temp[i] <= temp[i-1]){
	            ans = 0;
	            break;
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
