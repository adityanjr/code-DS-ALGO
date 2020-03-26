#include <iostream>
#include <string>

using namespace std;

string rev(string s){
    int n = s.size();
    
    for(int i = 0; i < n/2; i++){
        char c = s[n-i-1];
        s[n-i-1] = s[i];
        s[i] = c;
    }
    
    return s;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    string ans = "";
	    
	    int count = 0;
	    
	    for(int i = 0; i < s.size(); i++){
            if(count == 0){
                ans = ans + s[i];
                count++;
            }
            else if(s[i] == s[i-1]){
                count++;
            }
            else{
                ans = ans + to_string(count);
                ans = ans + s[i];
                count = 1;
            }
	    }
	    
	    if(count){
	        ans = ans + to_string(count);
	    }
	  
	    cout << rev(ans) << endl;
	    
	    test--;
	}
	
	return 0;
}
