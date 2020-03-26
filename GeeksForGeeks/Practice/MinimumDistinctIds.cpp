#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct comp{
    bool operator()(int& a, int& b){
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
	    int n, mm;
	    cin >> n;
	    
	    map<int, int> m;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        
	        if(m.find(num) == m.end()){
	            m[num] = 1;
	        }
	        else{
	            m[num]++;
	        }
	    }
	    
	    cin >> mm;
	    
	    priority_queue<int, vector<int>, comp> q;
	    
	    map<int, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        q.push(it->second);
	        it++;
	    }
	    
	    while(mm != 0 && !q.empty()){
	        if(mm < q.top()){
	            break;
	        }
	        mm -= q.top();
	        q.pop();
	    }
	    
	    cout << q.size() << endl;
	}
	
	return 0;
}
