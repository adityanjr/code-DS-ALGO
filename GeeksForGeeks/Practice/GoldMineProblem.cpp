#include <iostream>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, m, ans = 0;
	    cin >> n >> m;
	    
	    vector<vector<int> > temp(n, vector<int>(m));
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            cin >> temp[i][j];
	            ans = max(ans, temp[i][j]);
	        }
	    }
	 
	    vector<vector<int> > sol = temp;
	    
	    for(int j = 1; j < m; j++){
    	    for(int i = 0; i < n; i++){
    	        int leftTop = 0, left = sol[i][j-1], leftBottom = 0;
    	        if(i-1 >= 0){
    	            leftTop = sol[i-1][j-1];
    	        }        
    	        if(i+1 < n){
    	            leftBottom = sol[i+1][j-1];
    	        }
    	        
    	        sol[i][j] = temp[i][j] + max(left, max(leftTop, leftBottom));
    	        
    	        ans = max(ans, sol[i][j]);
    	    }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
