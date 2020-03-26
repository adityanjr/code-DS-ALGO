#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, x;
	    cin >> n >> x;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    int i = 0, ans = 0;
	    
	    while(i < n){
	        int j = i+1, k = n-1;
	        while(j < k){
	            int sum = temp[i] + temp[j] + temp[k];
	            if(sum < x){
	                ans += (k-j);
	                j++;
	            }
	            else{
	                k--;
	            }
	        }
	        i++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
