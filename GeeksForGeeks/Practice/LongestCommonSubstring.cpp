#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m, ans = 0;
	    cin >> n >> m;
	    
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    vector<vector<int> > temp(n+1, vector<int>(m+1, 0));
	    
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= m; j++){
	            if(s1[i-1] == s2[j-1]){
	                temp[i][j] = 1 + temp[i-1][j-1];
	            }
	            ans = max(ans, temp[i][j]);
	        }
	        
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
