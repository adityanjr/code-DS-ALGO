#include <iostream>
#include <map>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n, ans = 0;
	    cin >> n;
	    
	    map<int, bool> m;
	    
	    cout << "0 ";
	    m[0] = true;
	    
	    for(int i = 1; i < n; i++){
	        int temp = ans - i;
	        if((temp >= 0) && (m.find(temp) == m.end())){
	            ans = temp;
	        }
	        else{
	            ans = ans + i;
	        }
	        m[ans] = true;
	        cout << ans << " ";
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
