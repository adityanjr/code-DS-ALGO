// http://www.practice.geeksforgeeks.org/problem-page.php?pid=1541

#include <iostream>
#include <stack>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    stack<string> st;
	    
	    for(int i = 0; i < n; i++){
	        string s;
	        cin >> s;
	        
	        if(!st.empty()){
	            if(st.top() == s){
	                st.pop();
	            }
	            else{
	                st.push(s);
	            }
	        }
	        else{
	            st.push(s);
	        }
	    }
	    
	    cout << st.size() << endl;
	    
	    test--;
	}
	
	return 0;
}
