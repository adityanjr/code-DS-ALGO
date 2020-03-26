#include <iostream>

using namespace std;

string rev(string s){
    int n = s.size();
    
    for(int i = 0; i < n/2; i++){
        char c = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = c;
    }
    
    return s;
}

string add(string s, int num){
    int carry = num, n = s.size();
    
    string ans = "";
    
    for(int i = 0; i < n; i++){
        int sum = s[i] - '0' + carry;
        ans += to_string(sum%10);
        carry = sum/10;
    }
    
    if(carry){
        ans += to_string(carry);
    }
    
    return ans;
}

string nearestMultipleOf10(string s){
    int n = s.size();
    
    s = rev(s);
    int last = s[0] - '0';
    
    if(last <= 5){
        s[0] = '0';
        return rev(s);
    }
    
    return rev(add(s, 10 - last));
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    cout << nearestMultipleOf10(s) << endl; 
	}
	
	return 0;
}
