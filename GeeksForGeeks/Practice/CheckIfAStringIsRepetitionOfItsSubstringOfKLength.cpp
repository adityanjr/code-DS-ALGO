#include <iostream>
#include <string>
#include <map>

using namespace std;

string getString(string s, int start, int len){
    string ans = "";
    for(int i = 0; i < len; i++){
        ans = ans + s[start + i];
    }
    
    return ans;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, k;
	    cin >> n;
	    
	    string s;
	    cin >> s;
	    
	    cin >> k;
	    
	    map<string, int> m;
	    
	    int ans = 0;
	    
	    if(n%k == 0){
	        for(int i = 0; i < n; i = i + k){
	            string temp = getString(s, i, k);
	            if(m.find(temp) == m.end()){
	                m[temp] = 1;
	            }
	            else{
	                m[temp]++;
	            }
	            if(m.size() > 2){
	                break;
	            }
	        }
	        
	        if(m.size() == 1){
	            ans = 1;
	        }
	        else if(m.size() == 2){
	            map<string, int> :: iterator it = m.begin();
	            int a = it->second;
	            it++;
	            int b = it->second;
	            
	            if(a == 1 || b == 1){
	                ans = 1;
	            }
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
