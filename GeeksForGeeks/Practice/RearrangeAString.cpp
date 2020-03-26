#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int sum = 0, n = s.size();
	    
	    vector<int> temp(26, 0);
	    
	    for(int i = 0; i < n; i++){
	        if(isdigit(s[i])){
	            sum += s[i] - '0';
	        }
	        else{
	            temp[s[i]-'A']++;
	        }
	    }
	    
	    for(int i = 0; i < 26; i++){
	        for(int j = 0; j < temp[i]; j++){
	            cout << char('A' + i);
	        }
	    }
	    
	    if(sum){
	        cout << sum;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
