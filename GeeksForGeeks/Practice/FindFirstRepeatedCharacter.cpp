#include <iostream>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int n = s.size(), index = -1;
	    
	    map<char, bool> m;
	    
	    for(int i = 0; i < n; i++){
	        if(m.find(s[i]) == m.end()){
	            m[s[i]] = true;
	        }
	        else{
	            index = i;
	            break;
	        }
	    }
	    
	    if(index == -1){
	        cout << index;
	    }
	    else{
	        cout << s[index];
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
