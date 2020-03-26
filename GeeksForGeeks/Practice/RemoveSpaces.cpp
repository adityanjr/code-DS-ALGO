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
	    getline(cin, s);
	    
	    int i = 0, j = 0, n = s.size();
	    
	    while(i < n){
	        if(!isspace(s[i])){
	            s[j] = s[i];
	            j++;
	        }
	        i++;
	    }
	    
	    while(s.size() > j){
	        s.pop_back();
	    }
	    
	   // cout << s.size() << endl;
	    cout << s << endl;
	}
	
	return 0;
}
