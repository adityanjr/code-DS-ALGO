#include <iostream>
#include <map>

using namespace std;

string subs(string s, int i, int e){
    string ans = "";
    
    while(i <= e){
        ans += s[i];
        i++;
    }
    
    return ans;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    map<string, bool> m;
	    
	    int i = 0, n = s.size();
	    
	    while(i < n){
	        m[subs(s, i, i)] = true;
	        
	        // Odd length
	        int l = i-1, r = i+1;
	        
	        while(l >= 0 && r < n){
	            if(s[l] != s[r]){
	                break;
	            }
	            m[subs(s, l, r)] = true;
	            l--;
	            r++;
	        }
	        
	        // evenlength
	        l = i, r = i+1;
	        
	        while(l >= 0 && r < n){
	            if(s[l] != s[r]){
	                break;
	            }
	            m[subs(s, l, r)] = true;
	            l--;
	            r++;
	        }
	        
	        i++;
	    }
	    
	    cout << m.size() << endl;
	}
	
	return 0;
}
