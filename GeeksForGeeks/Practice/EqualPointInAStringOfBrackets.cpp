#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int n = s.size();
	    
	    vector<int> opening(n, 0);
	    vector<int> closing(n, 0);
	    
	    if(s[0] == '('){
	        opening[0] = 1;
	    }
	    if(s[n-1] == ')'){
	        closing[n-1] = 1;
	    }
	    
	    for(int i = 1; i < n; i++){
	        opening[i] = opening[i-1];
	        if(s[i] == '('){
	            opening[i]++;
	        }
	    }
	    
	    for(int i = n-2; i >= 0; i--){
	        closing[i] = closing[i+1];
	        if(s[i] == ')'){
	            closing[i]++;
	        }
	    }
	    
	    int i = 1;
	    bool found = false;
	    
	    while(i < n){
	        if(opening[i-1] == closing[i]){
	            found = true;
	            break;
	        }
	        i++;
	    }
	    
	    if(!found){
	        if(opening[n-1] == 0){
	            i = n;
	        }
	        else{
	            i = -1;
	        }
	    }
	    
	    cout << i << endl;
	    
	    test--;
	}
	
	return 0;
}
