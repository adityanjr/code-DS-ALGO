#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    vector<int> sol(n, -1);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    stack<int> st;
	    
	    for(int i = 0; i < n; i++){
	        if(!st.empty()){
	            while(!st.empty() && (temp[st.top()] < temp[i])){
	                sol[st.top()] = temp[i];
	                st.pop();
	            }
	        }
	        st.push(i);
	    }
	    
	    for(int i = 0; i < n; i++){
	        cout << sol[i] << " ";
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
