#include <iostream>

using namespace std;

string getWord(string s, int& i, int n){
    string word = "";
    
    while(i < n && s[i] != ' '){
        word += s[i];
        i++;
    }
    
    return word;
}

bool vowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
    }
    
    return false;
}

void make(string word, int& hard, int& easy){
    int i = 0, n = word.size(), vow = 0, con = 0;
    
    while(i < n){
        if(vowel(word[i])){
            vow++;
        }
        else{
            con++;
        }
        if(i+3 < n){
            if(!vowel(word[i]) && !vowel(word[i+1]) && !vowel(word[i+2]) && !vowel(word[i+3])){
                hard++;
                return;
            }
        }
        i++;
    }
    
    if(con > vow){
        hard++;
    }
    else{
        easy++;
    }
}

int main() {
	//code
	int test;
	cin >> test;
	
	string s;
    getline(cin, s);
	
	while(test--){
	    getline(cin, s);
	    
	    int n = s.size(), i = 0, hard = 0, easy = 0;
	    
	    while(i < n){
	        string word = getWord(s, i, n);
	        make(word, hard, easy);
	        i++;
	    }
	    
	    cout << 5*hard + 3*easy << endl;
	}
	
	return 0;
}
