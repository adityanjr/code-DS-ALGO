#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getNum(string s, int& i){
    string ans = "";
    
    while(i < s.size() && isdigit(s[i])){
        ans += s[i];
        i++;
    }
    
    return stoi(ans);
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int ans = 0, curr = -1, last = -1, k;
	    
	    cin >> k;
	    
	    string s;
	    cin >> s;
	    
	    int i = 0, n = s.size();
	    
	    stack<int> st;
	    
	    while(i < n){
	        if(s[i] == '('){
	            curr++;
	            last = i;
	        }
	        else if(s[i] == ')'){
	            if(last != i-1){
	                st.pop();
	            }
	            curr--;
	        }
	        else{
	            st.push(getNum(s, i));
	            if(curr == k){
	                ans += st.top();
	            }
	            i--;
	        }
	        i++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
