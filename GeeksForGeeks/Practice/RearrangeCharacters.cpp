#include <iostream>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int n = s.size();
	    
	    map<char, int> m;
	    
	    for(int i = 0; i < n; i++){
	        if(m.find(s[i]) == m.end()){
	            m[s[i]] = 1;
	        }
	        else{
	            m[s[i]]++;
	        }
	    }
	    
	    map<char, int> :: iterator it = m.begin();
	    
	    bool ans = true;
	    
	    if(n%2 == 0){
	        while(it != m.end()){
    	        if(it->second >= (n/2 + 1)){
    	            ans = false;
    	            break;
    	        }
    	        
    	        it++;
    	    }
	    }
	    else{
	        while(it != m.end()){
    	        if(it->second > (n/2 + 1)){
    	            ans = false;
    	            break;
    	        }
    	        
    	        it++;
    	    }    
	    }
	    
	    
	    cout << ans << endl;
	}
	
	return 0;
}
