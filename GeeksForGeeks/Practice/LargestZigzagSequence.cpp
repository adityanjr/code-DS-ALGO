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
	    
	    vector<vector<int> > temp(n, vector<int>(n));
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cin >> temp[i][j];
	        }
	    }
	    
	    int sol = temp[0][0];
	    
	    for(int i = 1; i < n; i++){
	        for(int j = 0; j < n; j++){
	            int maxi = 0;
	            for(int k = 0; k < n; k++){
	                if(k != j){
	                    maxi = max(temp[i-1][k], maxi);
	                }
	            }
	            temp[i][j] += maxi;
	            sol = max(sol, temp[i][j]);
	        }
	    }
	    
	    cout << sol << endl;
	    
	    test--;
	}
	
	return 0;
}
