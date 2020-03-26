#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct temp{
   int index, val;
};

struct comp{
    bool operator()(temp& a, temp& b){
        return (a.val < b.val) || (a.val == b.val && a.index > b.index);
        
    }
};

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, k, last = 0;
	    cin >> n >> k;
	    
	    vector<int> vec(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> vec[i];
	    }
	    
	    priority_queue<temp, vector<temp>, comp> q;
	    
	    for(int i = 0; i < k; i++){
	        temp t;
	        t.index = i;
	        t.val = vec[i];
	        q.push(t);
	    }
	    
	    cout << q.top().val << " ";
	    
	    for(int i = k; i < n; i++){
	        temp t;
	        t.index = i;
	        t.val = vec[i];
	        q.push(t);
	        while(!q.empty() && q.top().index <= last){
	            q.pop();
	        }
	        
	        last++;
	        cout << q.top().val << " ";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
