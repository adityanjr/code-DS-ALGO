#include <iostream>

using namespace std;

string rev(string s){
    string ans = "";
    
    for(int i = s.size()-1; i >= 0; i--){
        ans += s[i];
    }
    
    return ans;
}

string sum(string s1, string s2){
    int n1 = s1.size(), n2 = s2.size();
    
    s1 = rev(s1);
    s2 = rev(s2);
    
    int i = 0, carry = 0;
    
    string ans = "";
    
    while(i < n1 && i < n2){
        int sum = s1[i] - '0' + s2[i] - '0' + carry;
        carry = sum/10;
        ans += to_string(sum%10);
        i++;
    }
    
    while(i < n1){
        int sum = s1[i] - '0' + carry;
        carry = sum/10;
        ans += to_string(sum%10);
        i++;
    }
    
    while(i < n2){
        int sum = s2[i] - '0' + carry;
        carry = sum/10;
        ans += to_string(sum%10);
        i++;
    }
    
    if(carry){
        ans += to_string(carry);
    }
    
    if(ans.size() != s1.size()){
        return rev(s1);
    }
    
    return rev(ans);
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    cout << sum(s1, s2) << endl;
	}
	
	return 0;
}
