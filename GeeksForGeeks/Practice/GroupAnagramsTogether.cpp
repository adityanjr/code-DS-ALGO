#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string sortedString(string s){
    int n = s.size();
    
    vector<int> temp(n);
    
    for(int i = 0; i < n; i++){
        temp[i] = s[i];
    }
    
    sort(temp.begin(), temp.end());
    
    s = "";
    
    for(int i = 0; i < n; i++){
        s += temp[i];
    } 
    
    return s;
}

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
	        
	        s = sortedString(s);
	        
	        if(m.find(s) == m.end()){
	            m[s] = 1;
	        }
	        else{
	            m[s]++;
	        }
	    }
	    
	    vector<int> temp;
	    
	    map<string, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        temp.push_back(it->second);
	        it++;
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    for(int i = 0; i < temp.size(); i++){
	        cout << temp[i] << " ";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
