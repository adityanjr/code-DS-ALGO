#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	   
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    for(int i = n-1; i > 1; i--){
	        int k = 0, j = i-1;
	        while(k < j){
	            if(temp[k] + temp[j] == temp[i]){
	                ans++;
	                j--;
	            }
	            else if(temp[k] + temp[j] < temp[i]){
	                k++;
	            }
	            else{
	                j--;
	            }
	        }
	    }
	    
	    if(ans == 0){
	        ans = -1;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
