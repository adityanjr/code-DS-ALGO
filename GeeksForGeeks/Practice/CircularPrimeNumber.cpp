#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string getString(string s, int start, int len){
    string ans = "";
    
    for(int i = start; i < len; i++){
        ans = ans + s[i];
    }
    
    for(int i = 0; i < start; i++){
        ans = ans + s[i];
    }
    
    return ans;
}

bool prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    
    return true;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string n;
	    cin >> n;
	    
	    int ans = 1;
	    
	    for(int i = 0; i < n.size(); i++){
	        string test = getString(n, i, n.size());
	        if(!prime(stoi(test))){
	            ans = 0;
	            break;
	        }
	    }
    
        cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
