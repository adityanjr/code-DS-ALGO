#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
 {
	//code
	int test, num = pow(10, 9) + 7;
	cin >> test;
	
	while(test--){
	    int m, n;
	    cin >> m >> n;
	    
	    vector<vector<int> > temp(m, vector<int>(n, 1));
	    
	    for(int i = 1; i < m; i++){
	        for(int j = 1; j < n; j++){
	            temp[i][j] = (temp[i-1][j]%num + temp[i][j-1]%num)%num;
	        }
	    }
	    
	    cout << temp[m-1][n-1] << endl;
	}
	
	return 0;
}
