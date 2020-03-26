#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int>& temp, int start, int end){
    int ans = end+1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(temp[mid] == 1){
            ans = min(ans, mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    
    if(ans == temp.size()){
        return -1;
    }
    
    return ans;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int r, c, ans = -1, ind = -1;
	    cin >> r >> c;
	    
	    vector<vector<int> > temp(r, vector<int>(c));
	    
	    for(int i = 0; i < r; i++){
	        for(int j = 0; j < c; j++){
	            cin >> temp[i][j];
	        }
	    }
	    
	    for(int i = 0; i < r; i++){
	        int t = bs(temp[i], 0, c-1);
	        if(t > ans){
	            ind = i;
	            ans = t;
	        }
	    }
	    
	    cout << ind << endl;
	}
	
	return 0;
}
