#include <iostream>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, last = -1;
	    cin >> n;
	    
	    map<int, bool> m;
	    
	    for(int i = 0; i < n; i++){
	        int num;
	        cin >> num;
	        
	        m[num] = true;
	    }
	    
	    string ans = "Yes";
	    
	    map<int, bool> :: iterator it = m.begin();
	    
	    while(it != m.end()){
	        if(last == -1 || last+1 == it->first){
	            last = it->first;
	        }
	        else{
	            ans = "No";
	            break;
	        }
	        it++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
