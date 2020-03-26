#include <iostream>
#include <string>

using namespace std;

string rev(string s){
    int i = s.size() - 1;
    
    while(i >= 0 && s[i] == '0'){
        i--;
    }
    
    string ans = "";
    
    while(i >= 0){
        ans = ans + s[i];
        i--;
    }
    
    if(ans.size() == 0){
        return "0";
    }
    
    return ans;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    cout << rev(s) << endl;
	    
	    test--;
	}
	
	return 0;
}
