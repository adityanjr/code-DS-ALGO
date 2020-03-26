#include <iostream>

using namespace std;

string getString(string s, int start){
    string ans = "";
    
    for(int i = start; i < s.size(); i++){
        ans += s[i];
    }
    
    return ans;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int i = 0, n = s.size(), k;
	    
	    char c;
	    
	    cin >> c;
	    cin >> k;
	    
	    while(i < n && k){
	        if(s[i] == c){
	            k--;
	        }
	        i++;
	    }
	    
	    string ans = "Empty string";
	    
	    if(i < n){
	        ans = getString(s, i);
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
