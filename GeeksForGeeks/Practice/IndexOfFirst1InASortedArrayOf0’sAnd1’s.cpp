#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& temp, int start, int end){
    int ans = temp.size();
    
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

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cout << binarySearch(temp, 0, n-1) << endl;
	}
	
	return 0;
}
