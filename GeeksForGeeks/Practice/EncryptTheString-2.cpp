#include <iostream>
#include <string>

using namespace std;

string getVal(int a){
    if(a == 1){
        return "1";
    }
    else if(a == 2){
        return "2";
    }
    else if(a == 3){
        return "3";
    }
    else if(a == 4){
        return "4";
    }
    else if(a == 5){
        return "5";
    }
    else if(a == 6){
        return "6";
    }
    else if(a == 7){
        return "7";
    }
    else if(a == 8){
        return "8";
    }
    else if(a == 9){
        return "9";
    }
    else if(a == 10){
        return "a";
    }
    else if(a == 11){
        return "b";
    }
    else if(a == 12){
        return "c";
    }
    else if(a == 13){
        return "d";
    }
    else if(a == 14){
        return "e";
    }
    else if(a == 15){
        return "f";
    }
    return "0";
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

string getHexa(int a){
    string ans = "";
    
    while(a){
        ans = ans + getVal(a%16);
        a = a/16;
    }
    
    return rev(ans);
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int count = 0;
	    
	    string ans = "";
	    
	    for(int i = 0; i < s.size(); i++){
	        if(count == 0){
	            count = 1;
	            ans = ans + s[i];
	        }
	        else{
	            if(s[i] == s[i-1]){
	                count++;
	            }
	            else{
	                ans = ans + getHexa(count);
	                ans = ans + s[i];
	                count = 1;
	            }
	        }
	    }
	    
	    if(count){
	        ans = ans + getHexa(count);
	    }
	    
	    for(int i = ans.size()-1; i >= 0; i--){
	        cout << ans[i];
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
