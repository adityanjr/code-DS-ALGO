#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int x, y, n;
	    cin >> x >> y >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    int ans = 0;
	    
	    for(int i = 0; i < n; i++){
	        while(1){
	            ans++;
	            if(temp[i] <= x){
	                break;
	            }
	            temp[i] -= (x-y);
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
