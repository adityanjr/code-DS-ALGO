#include <iostream>
#include <map>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0;
	    cin >> n;
	    
	    map<string, int> m;
	    
	    for(int i = 0; i < n; i++){
	        string s;
	        cin >> s;
	        
	        if(m.find(s) == m.end()){
	            m[s] = 1;
	        }
	        else{
	            m[s]++;
	        }
	    }
	    
	    map<string, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        if(it->second == 2){
	            ans++;
	        }
	        
	        it++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
