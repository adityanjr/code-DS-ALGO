#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, ans = 0;
	    cin >> n;
	    
	    // Usin only A
	    ans += 1;
	    
	    // Usinc C once -> ans += n!/(n-1)!
	    if(n-1 >= 0){
	        ans += n;
	    }
	    
	    // Using C once, B once -> ans += n!/(n-2)!
        if(n-2 >= 0){
            ans += n*(n-1);
        }	    
    	    
	    // Using C once, B twice -> ans += n!/(n-3)!*2|
	    if(n-3 >= 0){
	        ans += (n*(n-1)*(n-2))/2;
	    } 
	    
	    // Using B once, ans += n!/(n-1)!
	    if(n-1 >= 0){
	        ans += n;
	    }
	    
	    // Using B twice, ans += n!/(n-2)!*2!
	    if(n-2 >= 0){
	        ans += (n*(n-1))/2;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
