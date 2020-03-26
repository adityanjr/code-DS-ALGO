#include <iostream>
#include <vector>

using namespace std;

bool hasOne(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            return true;
        }
    }
    
    return false;
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, count = -1;
	    cin >> n;
	    
	    vector<string> s(n);
	    vector<int> temp(n, 1);
	    
	    for(int i = 0; i < n; i++){
	        cin >> s[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(hasOne(s[i]) && temp[i] == 1){
	            count++;
	            for(int j = i+1; j < n; j++){
	                if(s[i] == s[j]){
	                    temp[j] = -1;
	                }
	            }
	            temp[i] = -1;
	            cout << count << " ";
	        }
	    }
	    
	    if(count == -1){
	        cout << "-1";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
