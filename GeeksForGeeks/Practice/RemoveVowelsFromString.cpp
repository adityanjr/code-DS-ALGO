#include <iostream>

using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    
    return false;
}

int main()
 {
	//code
	int test;
	cin >> test;
	cin.ignore();
	while(test--){
	    string s;
	    getline(cin, s);
	    
	    int i = 0, j = 0, n = s.size();
	    
	    while(i < n){
	        if(!isVowel(s[i])){
	            s[j] = s[i];
	            j++;
	        }
	        i++;
	    }
	    
	    while(j != n){
	        s.pop_back();
	        j++;
	    }
	    
	    cout << s << endl;
	}
	
	return 0;
}
