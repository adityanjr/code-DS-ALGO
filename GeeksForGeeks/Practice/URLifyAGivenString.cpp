#include <iostream>
#include <string>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	cin.ignore();
	while(test--){
	   string s;
	   getline(cin, s);
	   int n;
	   cin >> n;
	    
	    string ans = "";
	    
	    for(int i = 0; i < s.size(); i++){
	        if(isspace(s[i])){
	            ans += "%20";
	        }
	        else{
	            ans += s[i];
	        }
	    }
	    
	    cout << ans << endl;
	    cin.ignore();
	}
	
	return 0;
}
