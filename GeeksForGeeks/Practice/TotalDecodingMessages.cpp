#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    string s;
	    cin >> s;
	    
	    long long int ans = 0;
	    
	    vector<long long int> temp(n+1, 1);
	    
	    if(s[0] != '0'){
    	    for(int i = 1; i <= n; i++){
    	        if(s[i-1] == '0'){
    	            if(!(s[i-2] == '1' || s[i-2] == '2')){
    	                goto ANS;
    	            }
    	            temp[i] = temp[i-2];
    	        }
    	        else{
    	            if(i-2 >= 0){
    	                temp[i] = temp[i-1];
        	            if(s[i-2] == '1'){
        	                temp[i] += temp[i-2];
        	            }
        	            else if(s[i-2] == '2'){
        	                if(s[i-1] - '0' <= 6){
        	                    temp[i] += temp[i-2];
        	                }
        	            }
    	            }
    	            else{
    	                temp[i] = 1;
    	            }
    	        }
    	    }
    	    ans = temp[n];
	    }
	    
	    ANS:cout << ans << endl;
	}
	
	return 0;
}
