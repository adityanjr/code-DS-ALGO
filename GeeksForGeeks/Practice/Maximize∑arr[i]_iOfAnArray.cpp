#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, num = pow(10, 9)+7, ans = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    for(int i = 0; i < n; i++){
	        ans = (ans + ((i*temp[i])%num))%num;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
