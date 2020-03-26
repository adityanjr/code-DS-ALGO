#include <iostream>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    int ans = 0;
	    
	    for(int i = 0; i < n; i++){
	        ans = ans ^ temp[i];
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
