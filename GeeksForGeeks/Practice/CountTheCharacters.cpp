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
	    
	    int n, len = s.size(), ans = 0;
	    cin >> n;
	    
	    map<char, int> m;
	    
	    m[s[0]] = 1;
	    
	    for(int i = 1; i < len; i++){
	        if(s[i] == s[i-1]){
	            continue;
	        }
	        if(m.find(s[i]) == m.end()){
	            m[s[i]] = 1;
	        }
	        else{
	            m[s[i]]++;
	        }
	    }
	    
	    map<char, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        if(it->second == n){
	            ans++;
	        }
	        it++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
