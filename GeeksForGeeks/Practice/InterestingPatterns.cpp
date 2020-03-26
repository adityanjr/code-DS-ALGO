#include <iostream>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    int dim = 2*n - 1;
	    
	    vector<vector<int> > temp(dim, vector<int>(dim));
	    
	    int i = 0, j = 0;
	    
	    while(n){
	        int ti = i, tj = j;
	        
	        while(ti < dim-i){
	            temp[ti][j] = n;
	            temp[ti][dim-j-1] = n;
	            ti++;
	        }
	        
	        while(tj < dim-j){
	            temp[i][tj] = n;
	            temp[dim-i-1][tj] = n;
	            tj++;
	        }
	        
	        i++;
	        j++;
	        n--;
	    }
	    
	    for(int i = 0; i < dim; i++){
	        for(int j = 0; j < dim; j++){
	            cout << temp[i][j];
	        }
	        cout << " ";
	    }
	    
	    cout << endl;
	    
	    
	    test--;
	}
	
	return 0;
}
