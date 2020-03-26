#include <iostream>
#include <string>

using namespace std;

string getStr(string s){
    int i = 0, n = s.size();
    
    string ans = "";
    
    while(i < n){
        if(i == n-1){
            ans = ans + s[i];
        }
        else{
            if(s[i] == s[i+1]){
                while(s[i] == s[i+1] && i < n-1){
                    i++;
                }
            }
            else{
                ans = ans + s[i];
            }
        }
        i++;
    }
    
    return ans;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    string ans = "";
	    
	    while(1){
	        int n = s.size();
	        ans = getStr(s);
	        
	        s = ans;
	        
	        if(ans.size() == n){
	            break;
	        }
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	    
	}
	
	return 0;
}
