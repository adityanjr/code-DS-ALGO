#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int>& temp, int start, int end, int& ans){
    while(start <= end){
        int mid = start + (end-start)/2;
        
        if(temp[mid] >= temp[start]){
            ans = min(ans, temp[start]);
            start = mid+1;
        }
        else{
            ans = min(ans, temp[mid]);
            end = mid-1;
        }
    }
    
    return ans;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 10000;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cout << bs(temp, 0, n-1, ans) << endl;
	}
	
	return 0;
}
