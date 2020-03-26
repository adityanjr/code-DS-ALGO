#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n, ans = 0, curr = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	        temp[i] = temp[i] + curr;
	        curr = temp[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(temp[i] == 0){
	            ans++;
	        }
	        for(int j = 0; j < i; j++){
	            if(temp[i] - temp[j] == 0){
	                ans++;
	            }
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
