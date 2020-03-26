#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
 {
	//code
	
	long int num = pow(10, 6) + 3;
	
	vector<int> temp(num+1, 1);
	
	for(long int i = 2; i <= sqrt(num); i++){
	    if(temp[i] == 1){
    	    for(long int j = 2; i*j <= num; j++){
    	        temp[i*j] = -1;
    	    }
	    }
	}
	
	int test;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    long int i = n, j = n, ans = -1;
	    
	    while(i >= 2 || j <= num){
	        if(i >= 2){
    	        if(temp[i] == 1){
    	            ans = i;
    	            goto ANS;
    	        }
    	        i--;
	        }
	        if(j <= num){
    	        if(temp[j] == 1){
    	            ans = j;
    	            goto ANS;
    	        }
    	        j++;
	        }
	    }
	    
	    ANS:cout << ans << endl;
	}
	
	return 0;
}
