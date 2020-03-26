#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	vector<int> temp(pow(10, 6)+1, 1);
	
	for(int i = 2; i <= pow(10, 3); i++){
        if(temp[i] == 1){
	        for(int j = 2; i*j <= pow(10, 6); j++){
	            temp[i*j] = -1;
	        }
        }
    }
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    long long int sum = 0;
	    
	    for(int i = 2; i <= n; i++){
	        if(temp[i] == 1){
	            sum += i;
	        }
	    }
	    
	    cout << sum << endl;
	}
	
	return 0;
}
