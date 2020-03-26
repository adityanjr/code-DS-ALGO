#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, m;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    cin >> m;
	    
	    sort(temp.begin(), temp.end());
	    
	    int i = 0, j = m-1, ans = temp[n-1];
	    
	    while(j < n){
	        ans = min(ans, temp[j]-temp[i]);
	        i++;
	        j++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
