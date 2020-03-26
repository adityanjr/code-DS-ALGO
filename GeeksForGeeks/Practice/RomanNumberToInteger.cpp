#include <iostream>
#include <string>

using namespace std;

int getVal(char c){
    if(c == 'I'){
        return 1;
    }
    else if(c == 'V'){
        return 5;
    }
    else if(c == 'X'){
        return 10;
    }
    else if(c == 'L'){
        return 50;
    }
    else if(c == 'C'){
        return 100;
    }
    else if(c == 'D'){
        return 500;
    }
    return 1000;
}

bool isNextSymbolGreater(char c, char d){
    int val1 = getVal(c);
    int val2 = getVal(d);
    
    if(val1 < val2){
        return true;
    }
    return false;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int ans = 0, n = s.size(), i = 0;
	    
	    while(i < n){
	        if(i+1 < n && isNextSymbolGreater(s[i], s[i+1])){
	            ans = ans - getVal(s[i]);    
	        }
	        else{
	            ans = ans + getVal(s[i]);
	        }
	        i++;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
