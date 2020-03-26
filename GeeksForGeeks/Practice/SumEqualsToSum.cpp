#include <iostream>
#include <map>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0;
	    cin >> n;
	    
	    map<int, int> m;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        m[num] = num;
	    }
	    
	    map<int, int> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        map<int, int> :: iterator itt = it;
	        itt++;
	        while(itt != m.end()){
	            map<int, int> :: iterator ittt = itt;
	            ittt++;
    	        while(ittt != m.end()){
    	            int a = it->first, b = itt->first, c = ittt->first;
    	            if(m.find(a+b-c) != m.end()){
    	                if(m[a+b-c] != a && m[a+b-c] != b && m[a+b-c] != c){
        	                ans = 1;
        	                goto ANS;
    	                }
    	            }
    	            if(m.find(a-b+c) != m.end()){
    	                if(m[a-b+c] != a && m[a-b+c] != b && m[a-b+c] != c){
        	                ans = 1;
        	                goto ANS;
    	                }
    	            }
    	            if(m.find(-a+b+c) != m.end()){
    	                if(m[-a+b+c] != a && m[-a+b+c] != b && m[-a+b+c] != c){
        	                ans = 1;
        	                goto ANS;
    	                }
    	            }
    	            ittt++;
    	        }  
    	        itt++;
	        }
	        it++;
	    }
	    
	    ANS:cout << ans << endl;
	}
	
	return 0;
}
