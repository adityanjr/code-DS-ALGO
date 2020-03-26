#include <iostream>
#include <map>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int k, n = s.size(), last = 0, i = 0, count = 0, ans = -1;
	    cin >> k;
	    
	    map<char, int> m;
	    
	    while(i < n){
	        if(m.size() == k){
	            if(m.find(s[i]) == m.end()){
    	            m[s[last]]--;
    	            if(m[s[last]] == 0){
    	                m.erase(m.find(s[last]));
    	            }
    	            count--;
    	            last++;
	            }
    	        else{
    	            m[s[i]]++;
    	            count++;
    	            i++;
    	        }
    	        ans = max(ans, count);
	        }
	        else{
	            if(m.find(s[i]) == m.end()){
	                m[s[i]] = 1;
	            }
	            else{
	                m[s[i]]++;
	            }
	            count++;
	            i++;    
	        }
	    }
	    
	    if(m.size() == k){
	        ans = max(ans, count);
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
