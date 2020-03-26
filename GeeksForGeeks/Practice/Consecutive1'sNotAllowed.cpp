#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	//code
	int test, num = pow(10, 9) + 7;
	cin >> test;
	
	while(test--){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n+1, 0);
	    
	    temp[0] = 1;
	    temp[1] = 2;
	    
	    for(int i = 2; i <= n; i++){
	        temp[i] = (temp[i-1]%num + temp[i-2]%num)%num;
	    }
	    
	    cout << temp[n] << endl;
	}
	
	return 0;
}
