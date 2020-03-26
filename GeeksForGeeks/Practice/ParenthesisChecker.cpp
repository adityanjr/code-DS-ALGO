#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int test;
	cin >> test;

	while(test){
	    string s;
	    cin >> s;
	    
	    int n = s.size();
	    
	    string ans = "not balanced";
	    
	    stack<char> st;
	    
	    for(int i = 0; i < n; i++){
	        char c = s[i];
	        if(st.empty()){
	            st.push(c);
	        }
	        else{
	            if(c == '{' || c == '(' || c == '['){
	                st.push(c);
	            }
	            else if(c == '}' && !st.empty() && st.top() == '{'){
                    st.pop();
	            }
	            else if(c == ']' && !st.empty() && st.top() == '['){
                    st.pop();
	            }
	            else if(c == ')' && !st.empty() && st.top() == '('){
                    st.pop();
	            }
	            else{
	                break;
	            }
	        }
	    }
	    
	    if(st.empty()){
	        ans = "balanced";
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
