#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comp{
    bool operator()(int a, int b){
        if(a > b){
            return true;
        }
        return false;
    }  
};

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int k, n;
	    cin >> k >> n;
	    
	    vector<int> ans(n);
	    priority_queue<int, vector<int>, comp> q;
	    
	    for(int i = 0; i < k-1; i++){
	        int num;
	        cin >> num;
	        q.push(num);
	        ans[i] = -1;
	    }
	    
	    for(int i = k-1; i < n; i++){
	        int num;
	        cin >> num;
	        
	        q.push(num);    
	        if(q.size() > k){
	            q.pop();    
	        }
	        
	        ans[i] = q.top();
	        
	    }
	    
	    for(int i = 0; i < n; i++){
	        cout << ans[i] << " ";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
