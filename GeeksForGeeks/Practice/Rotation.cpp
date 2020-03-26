#include <iostream>
#include <vector>

using namespace std;

int checkIndex(vector<int> temp, int start, int end){
    if(start == end){
        return start;
    }
    else if(end - start == 1){
        if(temp[start] <= temp[end]){
            return start;
        }
        return end;
    }
    
    int mid = start + (end-start)/2;
    
    if(temp[mid] <= temp[end]){
        return checkIndex(temp, start, mid);
    }
    
    return checkIndex(temp, mid, end);
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cout << checkIndex(temp, 0, n-1) << endl;
	    
	    test--;
	}
	
	return 0;
}
