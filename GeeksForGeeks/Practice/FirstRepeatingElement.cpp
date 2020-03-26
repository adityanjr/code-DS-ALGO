#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, ans = -1;
	    cin >> n;
	    
	    vector<int> temp(n);
	    map<int, int> m;
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	        
	        if(m.find(temp[i]) == m.end()){
	            m[temp[i]] = 1;
	        }
	        else{
	            m[temp[i]]++;
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(m[temp[i]] >= 2){
	            ans = i+1;
	            break;
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
