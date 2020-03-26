#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, target, ans = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cin >> target;
	    
	    vector<map<int, int> > dp(n);
	    
	    for(int i = 0; i < n; i++){
	        dp[i][temp[i]] = 1;
	        for(int j = i-1; j >= 0; j--){
	           map<int, int> :: iterator it = dp[j].begin(); 
	           while(it != dp[j].end()){
	               int val = it->first + temp[i];
	               if(dp[i].find(val) != dp[i].end()){
	                   dp[i][val] += it->second;
	               }
	               else{
	                   dp[i][val] = it->second;
	               }
	               it++;
	           }
	        }
	        if(dp[i].find(target) != dp[i].end()){
	            ans += dp[i][target];
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
