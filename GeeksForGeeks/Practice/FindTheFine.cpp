#include <iostream>
#include <vector>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, date, ans = 0;
	    cin >> n >> date;
	    
	    vector<int> cars(n), fines(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> cars[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        cin >> fines[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        if((!(date%2) && cars[i]%2) || (date%2 && !(cars[i]%2))){
	            ans += fines[i];
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
