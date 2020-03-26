#include <iostream>
#include <map>

using namespace std;

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n, ans = 0;
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
	    
	    map<int, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        ans = ans + ((it->second)/2)*2;
	        it++;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
