#include <iostream>
#include <vector>

using namespace std;

int ls(vector<int>& temp){
    int ans = temp[0], n = temp.size();
    
    for(int i = 1; i < n; i++){
        if(temp[i] < ans){
            break;
        }
        ans = temp[i];
    }
    
    return ans;
}

int main()
 {
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
	    
	    cout << ls(temp) << endl;
	}
	
	return 0;
}
