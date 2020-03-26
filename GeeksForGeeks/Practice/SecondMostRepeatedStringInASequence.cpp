#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct temp{
    string s;
    int n;
};

struct compare{
    bool operator () (temp& a, temp& b){
        if(a.n < b.n){
            return true;
        }
        return false;
    }   
};

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    map<string, int> m;
	    
	    for(int i = 0; i < n; i++){
	        string s;
	        cin >> s;
	        
	        if(m.find(s) == m.end()){
	            m[s] = 1;
	        }
	        else{
	            m[s]++;
	        }
	    }
	    
	    priority_queue<temp, vector<temp>, compare> q;
	    
	    map<string, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        temp t;
	        t.s = it->first;
	        t.n = it->second;
	        q.push(t);
	       // cout << it->first << " : " << it->second << endl;
	        it++;
	    }
	    
	   // cout << "Popped : " << (q.top()).s << endl;
	    q.pop();
	    
	    cout << (q.top()).s << endl;
	}
	
	return 0;
}
