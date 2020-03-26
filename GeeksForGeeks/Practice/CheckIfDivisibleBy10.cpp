#include <iostream>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int ans = 0, n = s.size();
	    
	    if(s[n-1] == '0'){
	        if(n == 1){
	            ans = 1;
	            break;
	        }
	        
	        int c = 1, total = 0;
	        
	        for(int i = n-2; i >= 0; i--){
	            if(s[i] == '1'){
	                if(c%4 == 0){
	                    total += 6;
	                }
	                else if(c%3 == 0){
	                    total += 8;
	                }
	                else if(c%2 == 0){
	                    total += 4;
	                }
	                else{
	                    total += 2;
	                }
	            }
	            c = c%4;
	            c++;
	        }
	        
	        if(total%10 == 0){
	            ans = 1;
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
