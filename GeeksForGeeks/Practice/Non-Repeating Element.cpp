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
	    int n, ans = 10000;
	    cin >> n;
	    
	    vector<int> temp(n);
	    map<int, int> m;
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	        
	        if(m.find(temp[i]) == m.end()){
	            m[temp[i]] = i;
	        }
	        else{
	            m[temp[i]] = -1;
	        }
	    }
	    
	    map<int, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        if(it->second != -1){
	            ans = min(ans, it->second);
	        }
	        
	        it++;
	    }
	    
	    if(ans == 10000){
	        ans = 0;
	    }
	    else{
	        ans = temp[ans];
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
