#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	string s;
    getline(cin , s);
	
	while(test){
	    getline(cin , s);    
	    
	    //cout << s << endl;
	    
	    vector<int> temp(26, 0);
	    
	    int count = 26, ans = 0, n = s.size();
	    
	    for(int i = 0; i < n; i++){
	        int a = s[i];
	        if(a >= 65 && a <= 90){
	            if(temp[a-65] == 0){
	                temp[a-65] = 1;
	                count--;
	            }
	        }
	        else if(a >= 97 && a <= 122){
	            if(temp[a-97] == 0){
	                temp[a-97] = 1;
	                count--;
	            }
	        }
	    }
	    
	    if(!count){
	        ans = 1;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
