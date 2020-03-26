#include <iostream>
#include <vector>

using namespace std;

string getString(string s, int i, int j){
    string ans = "";
    
    for(int y = i; y <= j; y++){
        ans = ans + s[y];
    }
    
    return ans;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int n = s.size();
	    
	    vector<long long int> temp(n, 0);
	    
	    long long int ans = 0;
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j <= i; j++){
	            string t = getString(s, j, i);
	            temp[i] = temp[i] + stoll(t);
	        }
	        ans = ans + temp[i];
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
