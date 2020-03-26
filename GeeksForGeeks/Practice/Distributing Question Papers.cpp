#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m, ansA = 0, ansB = 0;
	    cin >> n >> m;
	    
	    vector<vector<char> > temp(n, vector<char>(m));
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            cin >> temp[i][j];
	            
	            if((i+j)%2 == 0 && temp[i][j] == 'B'){
	                ansA++;
	            }
	            else if((i+j)%2 != 0 && temp[i][j] == 'A'){
	                ansA++;
	            }
	            
	            if((i+j)%2 == 0 && temp[i][j] == 'A'){
	                ansB++;
	            }
	            else if((i+j)%2 != 0 && temp[i][j] == 'B'){
	                ansB++;
	            }
	        }
	    }
	    
	    cout << min(ansA, ansB) << endl;
	}
	
	return 0;
}
