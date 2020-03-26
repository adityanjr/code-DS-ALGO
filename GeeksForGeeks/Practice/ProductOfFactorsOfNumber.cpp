#include <iostream>
#include <cmath>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, num = pow(10, 9) + 7;
	    cin >> n;
	    
	    long int ans = 1;
	    
	    for(int i = 1; i <= sqrt(n); i++){
	        if(n%i == 0){
	            ans = (ans*i)%num;
	            if(i != n/i){
	                ans = (ans*(n/i))%num;
	            }
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
