#include <iostream>
#include <vector>

using namespace std;

int search(vector<vector<int> > temp, int r, int key, bool row){
    if(row){
        int start = 0, end = temp[r].size()-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(temp[r][mid] == key){
                return 1;
            }
            else if(temp[r][mid] > key){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return 0;
    }
    
    int start = 0, end = temp.size()-1;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(temp[mid][r] == key){
            return 1;
        }
        else if(temp[mid][r] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    
    return 0;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int rows, cols, ans = 0, key;
	    cin >> rows >> cols;
	    
	    vector<vector<int> > temp(rows, vector<int>(cols));
	    
	    for(int i = 0; i < rows; i++){
	        for(int j = 0; j < cols; j++){
	            cin >> temp[i][j];
	        }
	    }
	    
	    cin >> key;
	    
	    for(int i = 0; i < rows; i++){
	        if((temp[i][0] <= key) && (key <= temp[i][cols-1])){
	            ans = max(ans, search(temp, i, key, true));
	        }
	    } 
	    
	    for(int j = 0; j < cols; j++){
	        if((temp[0][j] <= key) && (key <= temp[rows-1][j])){
	            ans = max(ans, search(temp, j, key, false));
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
