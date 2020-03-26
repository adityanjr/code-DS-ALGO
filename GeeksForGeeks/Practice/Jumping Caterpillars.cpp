#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, cat, ans = 0;
	    cin >> n >> cat;
	    
	    vector<int> temp(cat);
	    vector<int> eaten(n+1, 0);
	    
	    for(int i = 0; i < cat; i++){
	        cin >> temp[i];
	        for(int j = 1; j*temp[i] <= n; j++){
	            eaten[j*temp[i]] = 1;
	        }
	    }
	    
	    for(int i = 1; i <= n; i++){
	        if(!eaten[i]){
	            ans++;
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
