#include <iostream>
#include <vector>

using namespace std;

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
	    
	    vector<int> m(n, 1);
	    
	    int maxi = temp[n-1];
	    
	    for(int i = n-2; i >= 0; i--){
	        if(temp[i] > maxi){
	            maxi = temp[i];
	        }
	        else{
	            m[i] = 0;
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(m[i] == 1){
	            cout << temp[i] << " ";
	        }
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
