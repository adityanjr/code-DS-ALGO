#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, k;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cin >> k;
	    
	    vector<int> sum(n, 0);
	    sum[0] = temp[0];
	    
	    for(int i = 1; i < n; i++){
	        sum[i] += (sum[i-1] + temp[i]);
	    }
	    
	    int ans = sum[k-1];
	    
	    for(int i = k; i < n; i++){
	        ans = max(ans, sum[i]);
	        for(int j = i-k; j >= 0; j--){
	            ans = max(ans, sum[i]-sum[j]);
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
