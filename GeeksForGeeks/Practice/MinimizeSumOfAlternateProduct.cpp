#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n, ans = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    sort(temp.begin(), temp.end());
	    
	    int i = 0, j = n-1;
	    
	    while(i < n/2){
	        ans = ans + temp[i]*temp[j];
	        i++;
	        j--;
	    }
	    
	    cout << ans << endl;
	    
	    test--;
	}
	
	return 0;
}
