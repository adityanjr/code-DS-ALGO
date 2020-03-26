#include <iostream>
#include <map>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string a, b;
	    cin >> a >> b;
	    
	    int n1 = a.size(), n2 = b.size(), i = 0;
	    
	    map<char, int> m;
	    
	    while(i < n1){
	        m[a[i]] = true;
	        i++;
	    }
	    
	    int ans = 0;
	    i = 0;
	    
	    while(i < n2){
	        if(m.find(b[i]) != m.end()){
	            ans = 1;
	            break;
	        }
	        i++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
