#include <iostream>

using namespace std;

string getSubstr(string& s, int start, int end){
    string ans = "";
    
    while(start <= end){
        ans += s[start];
        start++;    
    }
    
    return ans;
}

string rev(string s){
    int n = s.size();
    
    for(int i = 0; i < n/2; i++){
        char c = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = c;
    }
    
    return s;
}

string sum(string s1, string s2){
    s1 = rev(s1);
    s2 = rev(s2);
    
    string ans = "";
    
    int n1 = s1.size(), n2 = s2.size(), carry = 0, i = 0;
    
    while(i < n1 && i < n2){
        int sum = carry + s1[i] - '0' + s2[i] - '0';
        ans += to_string(sum%10);
        carry = sum/10;
        i++;
    }
    
    while(i < n1){
        int sum = carry + s1[i] - '0';
        ans += to_string(sum%10);
        carry = sum/10;
        i++;
    }
    
    while(i < n2){
        int sum = carry + s2[i] - '0';
        ans += to_string(sum%10);
        carry = sum/10;
        i++;
    }
    
    if(carry){
        ans += "1";
    }
    
    return rev(ans);
}

bool find(string& s, string s2, string s3, int start, bool first){
    int n = s.size();
    if(n == start){
        if(!first){
            return true;
        }
        return false;
    }
    
    string s1 = getSubstr(s, start, start+s3.size()-1);
    if(s1 == s3){
        // cout << s1 << endl;
        return find(s, s3, sum(s2, s3), start+s3.size(), false);
    }
    
    return false;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int n = s.size();
	    bool ans = false;
	    
	    for(int i = 0; i < n; i++){
	        string s1 = getSubstr(s, 0, i);
	        for(int j = i+1; j < n; j++){
	            string s2 = getSubstr(s, i+1, j);
	            ans = ans || find(s, s2, sum(s1, s2), j+1, true);
	            if(ans){
	                goto ANS;
	            }
	        }
	    }
	    
	    
	    ANS:cout << ans << endl;
	}
	
	return 0;
}
