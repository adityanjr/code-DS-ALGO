#include <iostream>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int k, ans = 0;
	    cin >> k;
	    
	    map<char, int> m;
	    priority_queue<int> q;
	    
	    for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = 1;
            }
            else{
                m[s[i]]++;
            }
	    }
	    
	    map<char, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	       // cout << "it->first " << it->first << ": it->second "
	       // << it->second << endl;
	        q.push(pow(it->second, 2));
	        it++;
	    }
	    
	    while(k){
	        int temp = sqrt(q.top()) - 1;
	       // cout << "temp " << temp;
	        q.pop();
	        q.push(pow(temp, 2));
	        k--;
	    }
	    
	   // cout << endl;
	    
	    while(!q.empty()){
	       // cout << "q.top " << q.top();
	        ans += q.top();
	        q.pop();
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
