#include <iostream>
#include <string>

using namespace std;

string removeZero(string s){
    int i = 0, n = s.size();
    
    while(s[i] == '0' && i < n){
        i++;
    }
    
    string ans = "";
    
    while(i < n){
        ans = ans + s[i];
        i++;
    }
    
    return ans;
}

string chooseMax(string s1, string s2){
    s1 = removeZero(s1);
    s2 = removeZero(s2);
    
    int n1 = s1.size(), n2 = s2.size();
    
    if(n1 > n2){
        return s1;
    }
    else if(n1 < n2){
        return s2;
    }
    
    for(int i = 0; i < n1; i++){
        if(s1[i] < s2[i]){
            return s2;
        }
        else if(s1[i] > s2[i]){
            return s1;
        }
    }
    
    return s1;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s, temp = "", ans = "";
	    cin >> s;
	    
	    int i = 0, n = s.size();
	    
	    while(i < n){
	        if(isdigit(s[i])){
	            temp = temp + s[i];
	        }
	        else{
	            temp = "";
	        }
	        ans = chooseMax(temp, ans);
	        i++;
	    }
	    
	    if(ans.size() == 0){
	        ans = "0";
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
