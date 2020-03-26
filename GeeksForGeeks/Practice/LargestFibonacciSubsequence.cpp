#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, maxi = -1;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	        maxi = max(temp[i], maxi);
	    }
	    
	    map<int, bool> m;
	    m[0] = true;
	    m[1] = true;
	    
	    int f = 0, s = 1;
	    
	    while(s <= maxi){
	        int t = f + s;
	        f = s;
	        s = t;
	        m[t] = true;
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(m.find(temp[i]) != m.end()){
	            cout << temp[i] << " ";
	        }
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
