#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, p;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cin >> p;
	    
	    int curr = 0, last = 0, ans = 0;
	    
	    for(int i = 0; i < n; i++){
	        curr = curr + last - temp[i];
	        last = temp[i];
	        if(curr < 0){
	            ans -= curr;
	            curr = 0;
	        }
	    }
	    
	    cout << ans*p << endl;
	}
	
	return 0;
}
