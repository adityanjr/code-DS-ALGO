#include <iostream>
#include <string>

using namespace std;

void make(string s, int n, int m, int& ans){
    int num = stoi(s);
    
    if(num > m){
        return;
    }
    else if((num >= n) && (num <= m)){
        ans++;
    }
    
    int last = s[s.size()-1] - '0';
    
    for(int i = 0; i <= 9; i++){
        if(abs(i-last) == 1){
            make(s + to_string(i), n, m, ans);
        }
    }
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n, m, ans = 0;
	    cin >> n >> m;
	    
	    if(n == 0){
	        ans++;
	    }
	    
	    for(int i = 1; i <= 9; i++){
	        make(to_string(i), n, m, ans);
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
