#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	cin.ignore();
	while(test--){
	    string s;
	    getline(cin, s);
	    
	    bool space = true;
	    
	    for(int i = 0; i < s.size(); i++){
	        if(isspace(s[i])){
	            space = true;
	        }
	        else{
	            if(space){
	                if(s[i] >= 97 && s[i] <= 122){
	                    s[i] = (s[i] - 'a' + 'A');
	                }
	            }
	            space = false;
	        }
	    }
	    
	    cout << s << endl;
	}
	
	return 0;
}
