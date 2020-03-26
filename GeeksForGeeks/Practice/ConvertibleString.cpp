#include <iostream>

using namespace std;

int findPos(string s, char c, int start){
    for(int i = start; i < s.size(); i += 2){
        if(s[i] == c){
            return i;
        }
    }
    
    return -1;
}

void swap(char& c, char& d){
    char temp = c;
    c = d;
    d = temp;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    int n1 = s1.size(), n2 = s2.size(), ans = 0;
	    
	    if(n1 == n2){
	        for(int i = 0; i < n1; i++){
	            if(s1[i] != s2[i]){
	                int pos = findPos(s1, s2[i], i+2);
	                if(pos == -1){
	                    break;
	                }
	                swap(s1[i], s1[pos]);
	            }
	        }
	        
	        if(s1 == s2){
	            ans = 1;
	        }
	        
	       // cout << s1 << " " << s2 << endl;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
