#include <iostream>
#include <map>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    map<int, bool> m;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        
	        m[num] = true;
	    }
	    
	    map<int, bool> :: iterator it = m.begin();
	    
	    int sum = 0;
	    
	    while(it != m.end()){
	        sum += it->first;
	        it++;
	    }
	    
	    cout << sum << endl;
	}
	
	return 0;
}
