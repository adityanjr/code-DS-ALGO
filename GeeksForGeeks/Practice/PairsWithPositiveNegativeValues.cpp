#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    map<int, bool> m;
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
            m[temp[i]] = true;
	    }
	    
	    map<int, bool> :: iterator it = m.begin();
	    
	    int count = 0;
	    
	    while(it != m.end()){
	        if(it->first > 0 && m.find(-it->first) != m.end()){
	            cout << -it->first << " " << it->first << " ";
	            count++;
	        }
	        it++;
	    }
	    
	    if(!count){
	        cout << "0";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
