// http://www.practice.geeksforgeeks.org/problem-page.php?pid=559

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int check(vector<int> pre, int start, int end){
    int ans = -1;
    for(int i = start; i <= end; i++){
        if(pre[i] > pre[start]){
            ans = i;
            break;
        }
    }
    
    return ans;
}

void convert(vector<int> pre, int start, int end, stack<int>& st){
    if(start > end){
        return;
    }
    st.push(pre[start]);
    
    int part = check(pre, start, end);
    
    if(part == -1){
        convert(pre, start+1, end, st);    
        return;
    }
    convert(pre, part, end, st);
    convert(pre, start+1, part-1, st);
}

bool valid(vector<int> pre, int start, int end){
    if(start >= end){
        return true;
    }
    
    int part = -1, i = start+1;
    
    while(i <= end){
        if(pre[i] > pre[start]){
            part = i;
            break;
        }
        i++;
    }
    
    if(part != -1){
        for(int i = part; i <= end; i++){
            if(pre[start] > pre[i]){
                return false;
            }
        }
    }
    
    return valid(pre, start+1, end);
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> pre(n);
	    stack<int> st;
	    
	    for(int i = 0; i < n; i++){
	        cin >> pre[i];
	    }
	    
	    bool v = valid(pre, 0, n-1);
	    
	    if(v){
    	    convert(pre, 0, n-1, st);
    	    
    	    while(!st.empty()){
    	        cout << st.top() << " ";
    	        st.pop();
    	    }
	    }
	    else{
	        cout << "NO";
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
