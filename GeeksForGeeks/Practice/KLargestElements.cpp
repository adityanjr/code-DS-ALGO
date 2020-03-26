#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, k;
	    cin >> n >> k;
	    
	    priority_queue<int, vector<int>, greater<int> > q;
	    
	    for(int i = 0; i < k; i++){
	        int num;
	        cin >> num;
	        q.push(num);
	    }
	    
	    for(int i = k; i < n; i++){
	        int num;
	        cin >> num;
	        if(q.top() < num){
	            q.pop();
	            q.push(num);
	        }
	    }
	    
	    vector<int> sol;
	    
	    while(!q.empty()){
	        sol.push_back(q.top());
	        q.pop();
	    }
	    
	    for(int i = sol.size()-1; i >= 0; i--){
	        cout << sol[i] << " ";
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
