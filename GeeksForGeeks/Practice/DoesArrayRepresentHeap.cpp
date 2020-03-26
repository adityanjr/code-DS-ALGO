#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 1;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        int lc = 2*i + 1, rc = 2*i + 2;
	        if(lc < n){
	            if(temp[lc] > temp[i]){
	                ans = 0;
	                break;
	            }
	        }
	        if(rc < n){
	            if(temp[rc] > temp[i]){
	                ans = 0;
	                break;
	            }
	        }   
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
