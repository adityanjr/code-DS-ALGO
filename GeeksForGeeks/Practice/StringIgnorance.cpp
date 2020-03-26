#include <iostream>
#include <string>
#include <map>

using namespace std;

string get(string s, int n){
    string ans = "";
    
    for(int i = 0; i < n; i++){
        ans += s[i];
    }
    
    return ans;
}

int main() {
	//code
	int test;
	cin >> test;
	
	string s;
    getline(cin, s);
	
	while(test--){
	    getline(cin, s);
	    
	    int n = s.size();
	    
	    map<char, int> m;
	    map<int, bool> replace;
	    
	    for(int i = 0; i < n; i++){
	        char c = s[i];
	        if(s[i] >= 65 && s[i] <= 95){
	            c = s[i] - 'A' + 97;
	        }
	        
	        if(m.find(c) == m.end()){
	            m[c] = 1;
	        }
	        else{
	            if(m[c]%2 == 0){
	                m[c] = 1;
	            }
	            else{
	                m[c] = 0;
	                replace[i] = true;
	            }
	        }
	    }
	    
	    int i = 0, j = 0;
	    
	    while(j < n){
	        if(replace.find(j) == replace.end()){
	            s[i] = s[j];
	            i++;
	        }
	        j++;
	    }
	    
	    cout << get(s, i) << endl;
	}
	
	return 0;
}
