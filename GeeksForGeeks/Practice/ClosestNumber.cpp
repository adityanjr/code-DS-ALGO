#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m;
	    cin >> n >> m;
	    
	    bool pos = true;
	    if(n < 0 && m > 0){
	        pos = false;
	        n = -n;
	    }
	    else if(n > 0 && m < 0){
	        pos = false;
	        m = -m;
	    }
	    else if(n < 0 && m < 0){
	        pos = false;
	        n = -n;
	        m = -m;
	    }
	    
	    
	    int f = (n/m)*m;
	    int ans = (n/m+1)*m;
	    
	    if(n-f < ans-n){
	        ans = f;
	    }
	    
	    if(!pos){
	        ans = -ans;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
