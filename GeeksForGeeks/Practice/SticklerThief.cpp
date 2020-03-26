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
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    vector<int> sol(n+1);
	    sol[0] = 0;
	    sol[1] = temp[0];
	    
	    if(n < 1){
	        goto ANS;
	    }
	    
	    sol[2] = temp[1];
	    
	    for(int i = 3; i <= n; i++){
	        sol[i] = temp[i-1] + max(sol[i-2], sol[i-3]);
	    }
	    
	   // for(int i = 0; i <= n; i++){
	   //     cout << sol[i] << " ";
	   // }
	    
	   // cout << endl;
	    
	    ANS:cout << max(sol[n], sol[n-1]) << endl;
	}
	
	return 0;
}
