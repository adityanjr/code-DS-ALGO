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
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    map<int, int> m;
	    
	    int ans = n-1;
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	        m[temp[i]] = i;
	    }
	    
	    map<int, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        ans = min(ans, it->second);
	        it++;
	    }
	    
	    cout << temp[ans] << endl;
	}
	
	return 0;
}
