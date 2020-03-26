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
	    
	    map<int, int> m;
	    
	    int i = 0, n = s.size();
	    
	    while(i < n){
	        if(m.find(s[i] - '0') == m.end()){
	            m[s[i] - '0'] = 1;
	        }
	        else{
	            m[s[i]- '0']++;
	        }
	        i++;
	    }
	    
	    if(m.find(0) != m.end()){
	        int curr = 1;
	        while(m.find(curr) == m.end()){
	            curr++;
	        }
	        cout << curr;
	        m[curr]--;
	    }
	    
	    map<int, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        while(it->second){
	            cout << it->first;
	            (it->second)--;
	        }
	        it++;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
