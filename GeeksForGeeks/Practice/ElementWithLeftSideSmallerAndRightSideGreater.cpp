#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = -1;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    vector<int> small(n, -1);
	    vector<int> great(n, -1);
	    
	    int mini = temp[n-1], maxi = temp[0];
	    
	    for(int i = n-2; i >= 0; i--){
	        if(temp[i] <= mini){
	            small[i] = 1;
	            mini = temp[i];
	        }
	    }
	    
	    for(int i = 1; i < n; i++){
	        if(temp[i] >= maxi){
	            great[i] = 1;
	            maxi = temp[i];
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(small[i] == 1 && great[i] == 1){
	            ans = temp[i];
	            break;
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
