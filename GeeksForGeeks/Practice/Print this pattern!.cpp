#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<vector<int> > temp(2 * n - 1, vector<int>(2 * n - 1));
	    
	    int start = 0, end = 2 * n - 2, num = n;
	    
	    while(start <= end){
	        for(int i = start; i <= end; i++){
	            temp[start][i] = num;
	            temp[end][i] = num;
	        }
	        
	        for(int i = start; i <= end; i++){
	            temp[i][start] = num;
	            temp[i][end] = num;
	        }
	        
	        num--;
	        start++;
	        end--;
	    }
	    
	    for(int i = 0; i < temp.size(); i++){
	        for(int j = 0; j < temp[0].size(); j++){
	            cout << temp[i][j];
	        }
	        cout << endl;
	    }
	}
	
	return 0;
}
