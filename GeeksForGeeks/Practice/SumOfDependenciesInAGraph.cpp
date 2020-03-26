#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int v, e, ans = 0;
	    cin >> v >> e;
	    
	    vector<vector<int> > temp(v, vector<int>());
	    
	    for(int i = 0; i < e; i++){
	        int from, to;
	        cin >> from >> to;
	        
	        temp[from].push_back(to);
	    }
	    
	    for(int i = 0; i < v; i++){
	        ans = ans + temp[i].size();
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
