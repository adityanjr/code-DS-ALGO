#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}

void mainFn(string s, string currS, int curr, vector<string>& v){
    int n = s.size();
    
    if(curr > n){
        return;
    }
    
    if(currS.size() > 0 && !isVowel(currS[currS.size()-1])){
        v.push_back(currS);
    }   
    
    for(int i = curr; i < n; i++){
        string ans = currS + s[i];
        mainFn(s, ans, i+1, v);
    }
}

void make(string s, vector<string>& v){
    int i = 0, n = s.size();
    
    while(i < n){
        if(isVowel(s[i])){
            string ans = "";
            ans += s[i];
            mainFn(s, ans, i+1, v);
        }
        i++;
    }
}

struct comp{
    bool operator()(string& a, string& b){
        int n = a.size(), m = b.size(), i = 0;
        
        while(i < n && i < m){
            if(a[i] < b[i]){
                return true;
            }
            else if(a[i] > b[i]){
                return false;
            }
            i++;
        }
        
        if(i == n){
            return true;
        }
        
        return false;
    }
};

void printV(vector<string>& v){
    map<string, bool> m;
    for(int i = 0; i < v.size(); i++){
        if(m.find(v[i]) == m.end()){
            m[v[i]] = true;
            cout << v[i] << " ";
        }
    }
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    vector<string> v;
	    
	    make(s, v);
	    
	    if(!v.size()){
	        cout << "-1";
	    }
	    else{
	        sort(v.begin(), v.end(), comp());
	        printV(v);
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
