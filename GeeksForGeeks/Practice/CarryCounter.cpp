#include <iostream>

using namespace std;

string rev(string s){
    string ans = "";
    
    int n = s.size()-1;
    
    while(n >= 0){
        ans += s[n];
        n--;
    }
    
    return ans;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    s1 = rev(s1);
	    s2 = rev(s2);
	    
	    int n = s1.size(), m = s2.size(), ans = 0, carry = 0, i = 0;
	    
	    while(i < n && i < m){
	        if(((s1[i] - '0') + (s2[i] - '0') + carry)/10){
	            ans++;
	        }
	        carry = ((s1[i] - '0') + (s2[i] - '0') + carry)/10;
	        i++;
	    }
	    
	    while(i < n){
	        if(((s1[i] - '0') + carry)/10){
	            ans++;
	        }
	        carry = ((s1[i] - '0') + carry)/10;
	        i++;
	    }
	    
	    while(i < m){
	        if(((s2[i] - '0') + carry)/10){
	            ans++;
	        }
	        carry = ((s2[i] - '0') + carry)/10;
	        i++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
