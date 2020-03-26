#include <iostream>
#include <vector>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	   // vector<long long int> temp(n+1, 0);
	    
	   // for(int i = 1; i <= n; i++){
	   //     temp[i] = i;
	   //     for(int j = 1; j < i; j++){
    //              if((2*j) <= i){
    //                  temp[i] = min(temp[i], temp[j] + 1 + i - (2*j));
    //              }
    //              else{
    //                  temp[i] = min(temp[i], temp[j] + i - j);
    //              }
	   //     }
	   // }
	    
	   // cout << temp[n] << endl;
	    
	    int ans = 0;
	    
	    while(n){
	        if(n%2 == 0){
	            n = n/2;
	        }
	        else{
	            n--;
	        }
	        ans++;
	    }

        cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}Minimum Operations
