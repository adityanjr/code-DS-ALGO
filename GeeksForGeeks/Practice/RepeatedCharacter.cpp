#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    map<char, vector<int> > m;
	    
	    int index = s.size();
	    
	    for(int i = 0; i < s.size(); i++){
	        m[s[i]].push_back(i);
	    }
	    
	    map<char, vector<int> > :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        if((it->second).size() >= 2){
	            index = min(index, (it->second)[0]);
	        }
	        it++;
	    }
	    
	    if(index == s.size()){
	        cout << "-1";
	    }
	    else{
	        cout << s[index];
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
