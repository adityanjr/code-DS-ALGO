#include <iostream>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int r, c, ans = 0, r1, c1, r2, c2;
	    cin >> r >> c;
	    
	    vector<vector<int> > temp(r, vector<int>(c));
	    
	    for(int i = 0; i < r; i++){
	        for(int j = 0; j < c; j++){
	            cin >> temp[i][j];
	        }
	    }
	    
	    cin >> r1 >> c1 >> r2 >> c2;
	    
	    for(int i = r1-1; i < r2; i++){
	        for(int j = c1-1; j < c2; j++){
	            ans = ans + temp[i][j];
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
