#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, i = 0;
	    cin >> n;
	    
	    vector<int> temp(n), ans;
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    while(i < n){
	        if(temp[i] != 0){
	            if(i < n){
	                if(temp[i] == temp[i+1]){
	                    ans.push_back(2 * temp[i]);
	                    i++;
	                }
	                else{
	                    ans.push_back(temp[i]);
	                }
	            }
	            else{
	                ans.push_back(temp[i]);
	            }
	        }
	        i++;
	    }
	    
	    while(ans.size() <= n){
	        ans.push_back(0);
	    }
	    
	    for(int i = 0; i < n; i++){
	        cout << ans[i] << " ";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
