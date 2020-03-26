#include <iostream>
#include <vector>

using namespace std;

string substr(string s, int start, int end){
    string ans = "";
    
    while(start <= end){
        ans += s[start];
        start++;
    }
    
    return ans;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	vector<string> main = {"R", "RY", "RYY"};
	
	while(test--){
	    string s, ans = "NO";
	    cin >> s;
	    
	    int n = s.size();
	    
	    vector<bool> temp(n+1, false);
	    temp[0] = true;
	    
	    for(int i = 1; i <= n; i++){
	        if(substr(s, i-1, i-1) == main[0]){
	            temp[i] = temp[i-1];
	        }
	        if(i-1 > 0){
	            if(substr(s, i-2, i-1) == main[1]){
	                temp[i] = temp[i-2];
	            }   
	        }
	        if(i-2 > 0){
	            if(substr(s, i-3, i-1) == main[2]){
	                temp[i] = temp[i-3];
	            }   
	        }
	    }
	    
	    if(temp[n]){
	        ans = "YES";
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
