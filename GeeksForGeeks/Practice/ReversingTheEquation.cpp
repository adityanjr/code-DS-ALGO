#include <iostream>

using namespace std;

string reverse(string s){
    int n = s.size();
    
    for(int i = 0; i < n/2; i++){
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
    
    return s;
}

string getNum(string s, int& i){
    string ans = "";
    
    while(i >= 0 && isdigit(s[i])){
        ans += s[i];
        i--;
    }
    
    return reverse(ans);
}

char getChar(string s, int& i){
    i--;
    return s[i+1];
}

string rev(string s){
    int i = s.size()-1;
    
    string ans = "";
    
    while(i >= 0){
        ans += getNum(s, i);
        if(i >= 0){
            ans += getChar(s, i);
        }
    }
    
    return ans;
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
	    
	    cout << rev(s) << endl;
	}
	
	return 0;
}
