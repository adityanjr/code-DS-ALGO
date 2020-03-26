#include <iostream>
#include <vector>

using namespace std;

int get1(vector<int> temp, int start, int end){
    int ans = end;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(temp[mid] == 1){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    
    return ans;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int rows, cols;
	    cin >> rows >> cols;
	    
	    vector<vector<int> > temp(rows, vector<int>(cols));
	    
	    for(int i = 0; i < rows; i++){
	        for(int j = 0; j < cols; j++){
	            cin >> temp[i][j];
	        }
	    }
	    
	    int ans = 0, count = 0;
	    
	    for(int i = 0; i < rows; i++){
	        int tempCount = cols - get1(temp[i], 0, cols-1);
	        if(count < tempCount){
	            ans = i;
	            count = tempCount;
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
