#include <iostream>
#include <stack>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int index, n = s.size();
	    cin >> index;
	    
	    stack<int> st;
	    
	    for(int i = 0; i < n; i++){
	        if(s[i] == '['){
	            st.push(i);
	        }
	        else if(s[i] == ']'){
	            if(st.top() == index){
	                cout << i << endl;
	                break;
	            }
	            st.pop();
	        }
	    }
	}
	
	return 0;
}
