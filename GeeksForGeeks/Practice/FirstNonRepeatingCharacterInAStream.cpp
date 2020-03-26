#include <iostream>
#include <map>
#include <string>

using namespace std;

void printFirst(string s, int i, int& j, map<char, int> m, bool& found){
    while(j <= i){
        if(m[s[j]] == 1){
            cout << s[j] << " ";
            found = true;
            break;
        }
        j++;
    }
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    string s = "";
	    
	    for(int i = 0; i < n; i++){
	        char c;
	        cin >> c;
	        s = s + c;
	    }
	    
	    int i = 0, j = 0;
	    
	    map<char, int> m;
	    
	    while(i < n){
	        if(m.find(s[i]) == m.end()){
	            m[s[i]] = 1;
	        }
	        else{
	            m[s[i]]++;
	        }
	        bool found = false;
	        printFirst(s, i, j, m, found);
	        
	        if(!found){
	            cout << "-1 ";
	        }
	        
	        i++;
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
