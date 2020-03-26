#include <iostream>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string str, pat;
	    cin >> str >> pat;
	    
	    map<char, bool> m;
	    
	    for(int i = 0; i < pat.size(); i++){
	        m[pat[i]] = true;
	    }
	    
	    int ans = -1;
	    
	    for(int i = 0; i < str.size(); i++){
	        if(m.find(str[i]) != m.end()){
	            ans = i;
	            break;
	        }
	    }
	    
	    if(ans == -1){
	        cout << "No character present";
	    }
	    else{
	        cout << str[ans];
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
