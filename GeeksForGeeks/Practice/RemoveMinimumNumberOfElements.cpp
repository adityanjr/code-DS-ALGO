#include <iostream>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m, ans = 0;
	    cin >> n >> m;
	    
	    map<int, int> m1, m2;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        
	        if(m1.find(num) == m1.end()){
	            m1[num] = 1;
	        }
	        else{
	            m1[num]++;
	        }
	    }
	    
	    for(int i = 0; i < m; i++){
	        int num;
	        cin >> num;
	        
	        if(m2.find(num) == m2.end()){
	            m2[num] = 1;
	        }
	        else{
	            m2[num]++;
	        }
	    }
	    
	    map<int, int> :: iterator it = m1.begin();
	    
	    while(it != m1.end()){
	        if(m2.find(it->first) != m2.end()){
	            ans += min(m2[it->first], it->second);
	        }
	        it++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
