#include <iostream>
#include <string>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	string s;
	getline(cin, s);
	
	while(test--){
	    string ans = "YES";
	    getline(cin, s);
	    
	   // cout << s << endl;
	    
	    int n = s.size(), i = 0;
	    int j = n-1;
	    
	    LOOP:while(i < j){
	        if(isspace(s[i])){
	            i++;
	            goto LOOP;
	        }
	        if(isspace(s[j])){
	            j--;
	            goto LOOP;
	        }
	        if(s[i] != s[j]){
	            ans = "NO";
	            break;
	        }
	        i++;
	        j--;
	    }
	    
	    cout << ans << endl;
	    
	}
	
	return 0;
}
