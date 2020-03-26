#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0;
	    cin >> n;
	    
	    map<int, vector<int> > m;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        
	        m[num].push_back(i);
	    }
	    
	    map<int, vector<int> > :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        ans = max(ans, (it->second)[(it->second).size()-1] - (it->second)[0]);
	        
	        it++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
