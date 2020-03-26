#include <iostream>

using namespace std;

string rev(string s){
    int n = s.size();
    
    for(int i = 0; i < n/2; i++){
        char c = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = c;
    }
    
    return s;
}

string getBinary(int n){
    string ans = "";

    while(n){
        ans += to_string(n%2);
        n = n/2;
    }
    
    return rev(ans);
}

string make(string s, int curr, int n){
    if(curr >= n){
        return s;
    }
    
    string ans = "";
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            ans += "01";
        }
        else{
            ans += "10";
        }
    }
    
    return make(ans, curr+1, n);
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int m, k, n;
	    cin >> m >> k >> n;
	    
	    string binary = getBinary(m);
	    string ans = make(binary, 0, n);
	    
	    cout << ans[k] << endl;
	}
	
	return 0;
}
